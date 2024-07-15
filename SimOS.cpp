/*
Author: Ibrahim Moftah
*/

#include "SimOS.h"

SimOS::SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize)
    : numberOfDisks_(numberOfDisks), amountOfRAM_(amountOfRAM), pageSize_(pageSize),
      nextPID_(1), runningPID_(NO_PROCESS) {
    // Initialize memory, memoryMap, and disks vectors
    memoryMap_.resize(amountOfRAM / pageSize, false);
    disks_.resize(numberOfDisks);
}

void SimOS::NewProcess() {
    // Creating a new process
    Process newProcess{nextPID_++, NO_PROCESS, (Status::ready), {}};

    if (runningPID_ == NO_PROCESS) {
        // If no process is running, run the new process immediately
        runningPID_ = newProcess.PID;
        newProcess.status = Status::running;
    } else {
        // Add the new process to the ready queue
        readyQueue_.push_back(newProcess);
    }
    // Add the new process to the processes vector
    processes_.push_back(newProcess);
}

void SimOS::SimFork() {
    // Check if CPU is idle, if so, cannot fork
    if (!IsRunning()) {
        throw std::logic_error("No process running.");
    }

    // Creating a new child process
    Process child{nextPID_++, runningPID_, (Status::ready), {}};

    // Adding the new child process PID to the children vector of the currently running process(parent)
    processes_[FindProcessIndex(runningPID_)].children.push_back(child.PID);

    // Add the new process to the ready queue
    readyQueue_.push_back(child);

    // Add the new process to the processes vector
    processes_.push_back(child);
}

void SimOS::SimExit() {
    // Check if CPU is idle, if so, cannot exit
    if (!IsRunning()) {
        throw std::logic_error("CPU is idle, cannot exit.");
    }

    // Finding the Index of the current running process within the processes vector
    int runningIndex = FindProcessIndex(runningPID_);

    // updating the process current state to terminated
    processes_[runningIndex].status = Status::terminated;

    // Removing the terminated process from the ready queue
    removeFromDeque(FindReadyQueueIndex(runningPID_));

    // Terminating all children processes of the terminated process 
    CascadeTerminate(runningPID_);

    // Release memory
    ReleaseMemory(runningPID_);

    // Get references to the running process and its parent
    Process& runningProcess = processes_[runningIndex];
    int parentPID = runningProcess.parentPID;
    Process& parentProcess = processes_[FindProcessIndex(parentPID)];

    // If the running process has a parent and the parent is waiting
    if (runningProcess.parentPID != NO_PROCESS && parentProcess.status == Status::waiting) {       
        bool foundWaitingChild = false;
        for (auto it = parentProcess.children.begin(); it != parentProcess.children.end(); ++it) {
            if (processes_[FindProcessIndex(*it)].status == Status::terminated) {
                foundWaitingChild = true;
                break;
            }
        }
        
        if (foundWaitingChild) {
            // Parent was waiting for a child (now zombie), add it to ready queue
            processes_[FindProcessIndex(parentPID)].status = Status::ready;
            readyQueue_.push_back(parentProcess);
        }
    // If the running process has a parent but the parent is not waiting
    } else if (runningProcess.parentPID != NO_PROCESS && parentProcess.status != Status::waiting) {
        // Set the running process status to zombie
        processes_[runningIndex].status = Status::zombie;
    }

    // If there are processes in the ready queue
    if (!readyQueue_.empty()) {
        // Set the front of the ready queue as the new running process
        runningPID_ = readyQueue_.front().PID;
        // Remove the front process from the ready queue
        readyQueue_.pop_front();          
        // Find and change the now current running process status to running
        processes_[FindProcessIndex(runningPID_)].status = Status::running;
    } else {
        // If ready queue is empty, set runningPID to NO_PROCESS (CPU idle)
        runningPID_ = NO_PROCESS;
    }
}

void SimOS::SimWait() {
    // Check if CPU is idle, if so, cannot wait
    if (!IsRunning()) {
        throw std::logic_error("CPU is idle, cannot wait.");
    }

    // Get reference to the running process
    Process& runningProcess = processes_[FindProcessIndex(runningPID_)];

    // Check if there are any zombie children
    bool foundZombie = false;
    for (int childPID : runningProcess.children) {
        if (processes_[FindProcessIndex(childPID)].status == Status::zombie) {
            // Found a zombie child
            foundZombie = true;
            // Remove the zombie child from the list of children
            int childIndex = FindChildIndex(runningProcess, childPID);
            runningProcess.children.erase(runningProcess.children.begin() + childIndex);
            // Release memory associated with the zombie child
            ReleaseMemory(childPID);
            // Mark the zombie child as terminated
            processes_[FindProcessIndex(childPID)].status = Status::terminated;
            break;
        }
    }

    // If no zombie child was found
    if (!foundZombie) {
        // Mark the running process as waiting
        processes_[FindProcessIndex(runningPID_)].status = Status::waiting;

        // If there are processes in the ready queue
        if (!readyQueue_.empty()) {
            // Set the front of the ready queue as the new running process
            runningPID_ = readyQueue_.front().PID;
            // Remove the front process from the ready queue
            readyQueue_.pop_front();          
            // Find and change the now current running process status to running
            processes_[FindProcessIndex(runningPID_)].status = Status::running;
        } else {
            // If ready queue is empty, set runningPID to NO_PROCESS (CPU idle)
            runningPID_ = NO_PROCESS;
        }
    }

}

void SimOS::TimerInterrupt() {
    // Check if CPU is idle, if so, cannot timer interrupt
    if (!IsRunning()) {
        throw std::logic_error("CPU is idle, cannot handle timer interrupt.");
    }

    // Set the status of the currently running process to ready
    processes_[FindProcessIndex(runningPID_)].status = Status::ready;

    // Add the currently running process back to the ready queue
    readyQueue_.push_back(processes_[FindProcessIndex(runningPID_)]);
    
    // If there are processes in the ready queue
    if (!readyQueue_.empty()) {
        // Set the front of the ready queue as the new running process
        runningPID_ = readyQueue_.front().PID;
        // Remove the front process from the ready queue
        readyQueue_.pop_front();          
        // Find and change the now current running process status to running
        processes_[FindProcessIndex(runningPID_)].status = Status::running;
    } else {
        // If ready queue is empty, set runningPID to NO_PROCESS (CPU idle)
        runningPID_ = NO_PROCESS;
    }
}

void SimOS::DiskReadRequest(int diskNumber, std::string fileName) {
    // Check if CPU is idle, if so, cannot handle disk read request
    if (!IsRunning()) {
        throw std::logic_error("No process running. 2");
    }

    // Check if the disk number is valid
    if (!IsDiskValid(diskNumber)) {
        throw std::out_of_range("Invalid disk number.");
    }

    // Create a file read request object with the current process ID and file name
    FileReadRequest request{runningPID_, fileName};

    // Push the file read request into the I/O queue of the specified disk
    disks_[diskNumber].ioQueue.push_back(request);

    // Set the status of the current process to waiting
    processes_[FindProcessIndex(runningPID_)].status = Status::waiting;

    // If there are processes in the ready queue
    if (!readyQueue_.empty()) {
        // Set the front of the ready queue as the new running process
        runningPID_ = readyQueue_.front().PID;
        // Remove the front process from the ready queue
        readyQueue_.pop_front();          
        // Find and change the now current running process status to running
        processes_[FindProcessIndex(runningPID_)].status = Status::running;
    } else {
        // If ready queue is empty, set runningPID to NO_PROCESS (CPU idle)
        runningPID_ = NO_PROCESS;
    }
}

void SimOS::DiskJobCompleted(int diskNumber) {
    // Check if the disk number is valid
    if (!IsDiskValid(diskNumber)) {
        throw std::out_of_range("Invalid disk number.");
    }

    // If the I/O queue of the disk is not empty
    if (!disks_[diskNumber].ioQueue.empty()) {
        // Get the completed job from the front of the I/O queue
        FileReadRequest& completedJob = disks_[diskNumber].ioQueue.front();

        if (runningPID_ != NO_PROCESS)
        {
            // Set the status of the process associated with the completed job to ready
            processes_[FindProcessIndex(completedJob.PID)].status = Status::ready;
            // Add the process back to the ready queue
            readyQueue_.push_back(processes_[FindProcessIndex(completedJob.PID)]);
        } else {
            // Set the status of the process associated with the completed job to running if there are no running process
            processes_[FindProcessIndex(completedJob.PID)].status = Status::running;
            // Set the completed job as the new running process
            runningPID_ = completedJob.PID;
        }

        // Remove the completed job from the I/O queue
        disks_[diskNumber].ioQueue.pop_front();
    }
}

void SimOS::AccessMemoryAddress(unsigned long long address) {
    // Check if CPU is idle, if so, cannot fork
    if (!IsRunning()) {
        throw std::logic_error("No process running. 3");
    }

    // Calculate the page number based on the address and page size
    unsigned long long pageNumber = address / pageSize_;

    // If pageNumber is above the possible pages in the system
    if (pageNumber >= amountOfRAM_ / pageSize_)
    {
        return;
    }
    
    // Page already in RAM, update "recently used" information
    for (auto& item : memory_) {
        if (item.pageNumber == pageNumber && item.PID == runningPID_) {
            // Iterate through the LRU queue to find and update the recently used item
            for (auto it = lruQueue_.begin(); it != lruQueue_.end(); ++it) {
                if (it->pageNumber == pageNumber && it->PID == runningPID_) {
                    // Move the item to the tail of the queue (recently used)
                    lruQueue_.push_back(*it);
                    // Remove the item from its current position
                    lruQueue_.erase(it);
                    return;
                }
            }
        }
    }

    // Page not in RAM, check for available frame
    for (size_t i = 0; i < memoryMap_.size(); ++i) {
        if (!memoryMap_[i]) {
            // Mark the frame as used
            memoryMap_[i] = true;
            // Create a new memory item for the page
            MemoryItem newItem{pageNumber, i, runningPID_};
            // Add the new item to memory
            memory_.push_back(newItem);
            // Add the new item to the LRU queue
            lruQueue_.push_back(newItem);
            return;
        }
    }

    // If no available frame, evict least recently used
    if (memory_.size() == memoryMap_.size()) {
        // Retrieve the least recently used item from the front of the LRU queue
        MemoryItem evicted = lruQueue_.front();
        lruQueue_.pop_front();

        // Create a new memory item for the page using the same frame number
        MemoryItem newItem{pageNumber, evicted.frameNumber, runningPID_};

        // Update the memory with the new item, replacing the evicted item
        for (auto it = memory_.begin(); it != memory_.end(); ++it) {
            if (it->pageNumber == evicted.pageNumber && it->PID == evicted.PID) {
                *it = newItem;
                break;
            }
        }
        // Add the new item to the tail of the LRU queue
        lruQueue_.push_back(newItem);
    }
}

int SimOS::GetCPU() {
    // Return the PID of the currently running process
    return runningPID_;
}

std::deque<int> SimOS::GetReadyQueue() {
    // Create a deque to store the PIDs of processes in the ready queue
    std::deque<int> readyPIDs;

    // Iterate through each process in the ready queue
    for (const Process& process : readyQueue_) {
        // Push the PID of the current process into the deque
        readyPIDs.push_back(process.PID);
    }

    // Return the deque containing the PIDs of processes in the ready queue
    return readyPIDs;
}

MemoryUsage SimOS::GetMemory() {
    // Return the MemoryUsage vector describing all currently used frames of RAM
    return memory_;
}

FileReadRequest SimOS::GetDisk(int diskNumber) {
    // Check if the disk number is valid
    if (!IsDiskValid(diskNumber)) {
        throw std::out_of_range("Invalid disk number. 2");
    }

    // If the I/O queue of the disk is not empty
    if (!disks_[diskNumber].ioQueue.empty()) {
        // Return the front file read request from the I/O queue
        return disks_[diskNumber].ioQueue.front();
    }

    // If the I/O queue is empty, return an empty FileReadRequest object
    return {};
}

std::deque<FileReadRequest> SimOS::GetDiskQueue(int diskNumber) {
    // Check if the disk number is valid
    if (!IsDiskValid(diskNumber)) {
        throw std::out_of_range("Invalid disk number. 3");
    }

    // Get a reference to the I/O queue of the specified disk
    const std::deque<FileReadRequest>& ioQueue = disks_[diskNumber].ioQueue;

    // Create a new deque to store the elements after index 0(removing index 0 being the current running File Read Request)
    std::deque<FileReadRequest> newQueue(ioQueue.begin() + 1, ioQueue.end());

    // Return the new deque
    return newQueue;
}

void SimOS::ReleaseMemory(int PID) {
    // Create an iterator to iterate over the memory container
    auto it = memory_.begin();
    // Iterate through each memory item
    while (it != memory_.end()) {
        // Check if the item belongs to the specified process
        if (it->PID == PID) {
            // Free the frame in memory by setting the corresponding entry in memoryMap to false
            memoryMap_[it->frameNumber] = false;
            // Erase the item from the memory container
            it = memory_.erase(it);
        } else {
            // Move to the next item
            ++it;
        }
    }
}

void SimOS::CascadeTerminate(int PID) {
    // Iterate through each child process of the specified PID
    for (int child : processes_[FindProcessIndex(PID)].children) {
        // Set the status of the child process to terminated
        processes_[FindProcessIndex(child)].status = Status::terminated;

        // Remove the child process from the ready queue if it's in it
        removeFromDeque(FindReadyQueueIndex(child));

        // Recursively terminate all children processes of the current child process
        CascadeTerminate(child);
    }
}

void SimOS::removeFromDeque(int index) {
    // Check if the index is valid
    if (index < 0 || static_cast<unsigned int>(index) >= readyQueue_.size()) {
        // If the index is invalid, return without performing any operation
        return;
    }

    // Shift elements in the deque to remove the element at randomIndex
    for (size_t i = index + 1; i < readyQueue_.size(); ++i) {
        readyQueue_[i - 1] = readyQueue_[i];
    }

    // Remove the last element from the deque
    readyQueue_.pop_back();
}

int SimOS::FindProcessIndex(int PID) {
    // Iterate through the processes vector
    for (size_t i = 0; i < processes_.size(); ++i) {
        // Check if the PID of the current process matches the given PID
        if (processes_[i].PID == PID) {
            // If a match is found, return the index
            return static_cast<int>(i);
        }
    }
    // If no matching PID is found, return -1
    return -1;
}

int SimOS::FindReadyQueueIndex(int PID) {
    // Iterate through the readyQueue deque
    for (size_t i = 0; i < readyQueue_.size(); ++i) {
        // Check if the PID of the current process in the readyQueue matches the given PID
        if (readyQueue_[i].PID == PID) {
            // If a match is found, return the index
            return static_cast<int>(i);
        }
    }
    // If no matching PID is found, return -1
    return -1;
}

int SimOS::FindChildIndex(const Process& process, int childPID) {
    int index = 0;
    // Iterate through the children PIDs of the specified process
    for (int child : process.children) {
        // Check if the current child PID matches the given childPID
        if (child == childPID) {
            // If a match is found, return the index of the child in the parent's children list
            return index;
        }
        // Increment the index for the next child
        ++index;
    }
    // If the child with the given PID is not found, return -1
    return -1;
}

bool SimOS::IsDiskValid(int diskNumber) {
    // Check if the disk number is within the valid range of disks
    return diskNumber >= 0 && diskNumber < numberOfDisks_;
}

bool SimOS::IsRunning() {
    // Check if the CPU is running a process
    return runningPID_ != NO_PROCESS;
}

// std::vector<Process> SimOS::GetAllProcesses() {
//     // Return the processes vector containing all the processes
//     return processes_;
// }

// void SimOS::printProcess(const Process& process) {
//     // Print the PID, Parent PID, and Status of the given process
//     std::cout << "PID: " << process.PID << ", Parent PID: " << process.parentPID << ", Status: " << getStatus(process) << std::endl;
// }

// std::string SimOS::getStatus(Process process) {
//     // Check the status of the given process and return a string representation of the status
//     if (process.status == Status::running) {
//         return "running";
//     } else if (process.status == Status::ready) {
//         return "ready";
//     } else if (process.status == Status::waiting) {
//         return "waiting";
//     } else if (process.status == Status::zombie) {
//         return "zombie";
//     } else if (process.status == Status::terminated) {
//         return "terminated";
//     } else {
//         // If the status is unexpected, return "Unknown"
//         return "Unknown";
//     }
// }
