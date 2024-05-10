/*
CSCI340 Spring 2024
Project 1
Ibrahim Moftah
*/

#ifndef SIMOS_H
#define SIMOS_H

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>

// Structure representing a file read request
struct FileReadRequest
{
    int PID{0}; // Process ID
    std::string fileName{""}; // Name of the file to be read
};

// Structure representing an item in memory
struct MemoryItem
{
    unsigned long long pageNumber; // Page number
    unsigned long long frameNumber; // Frame number
    int PID; // PID of the process using this frame of memory
};

// Enum representing the status of a process
enum class Status {
    running,
    ready,
    waiting,
    zombie,
    terminated
};

// Structure representing a process
struct Process {
    int PID; // Process ID
    int parentPID; // Parent process ID
    Status status; // Status of the process
    std::deque<int> children; // List of child processes
};

// Structure representing a disk
struct Disk {
    // Front element in the I/O Queue is the current running File Read Request
    std::deque<FileReadRequest> ioQueue; // Queue of I/O requests
};

// Alias for memory usage represented as a vector of MemoryItem
using MemoryUsage = std::vector<MemoryItem>;

constexpr int NO_PROCESS{ 0 }; // Constant representing absence of a process

// Class representing an operating system simulation
class SimOS {
public:
    // Constructor to initialize the simulation with specified parameters
    SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);

    // Functions to simulate various OS operations
    void NewProcess(); // Simulate creation of a new process
    void SimFork();    // Simulate process forking
    void SimExit();    // Simulate process termination
    void SimWait();    // Simulate process waiting
    void TimerInterrupt(); // Simulate timer interrupt
    void DiskReadRequest(int diskNumber, std::string fileName); // Simulate disk read request
    void DiskJobCompleted(int diskNumber); // Simulate completion of disk job
    void AccessMemoryAddress(unsigned long long address); // Simulate memory access
    int GetCPU(); // Returns the PID of the process currently using the CPU
    std::deque<int> GetReadyQueue(); // Returns the std::deque with PIDs of processes in the ready-queue
    MemoryUsage GetMemory(); // Returns MemoryUsage vector describing all currently used frames of RAM
    FileReadRequest GetDisk(int diskNumber); // Returns an object with PID of the process served by specified disk and the name of the file read for that process
    std::deque<FileReadRequest> GetDiskQueue(int diskNumber); // Returns the I/O-queue of the specified disk

    // Helper functions
    // std::vector<Process> GetAllProcesses(); // Returns Process vector of all processes
    // void printProcess(const Process& process); // Prints process PID, Parent PID, and Status

private:

    // Member variables
    const int numberOfDisks_; // Number of disks in the system
    const unsigned int pageSize_; // Page size of memory
    std::deque<Process> readyQueue_; // Queue for processes ready to execute
    std::vector<Process> processes_; // Vector to store all processes in the system
    std::vector<Disk> disks_; // Vector to store disk states
    std::vector<bool> memoryMap_; // Vector to represent memory map (true if memory is occupied, false otherwise)
    MemoryUsage memory_; // Struct to represent memory usage
    std::deque<MemoryItem> lruQueue_; // Queue for least recently used memory items
    int nextPID_; // The PID of the next process to be created
    int runningPID_; // The PID of the process currently using the CPU

    // Helper functions
    void ReleaseMemory(int PID); // Release memory occupied by a process
    void CascadeTerminate(int PID); // Terminate a process and its children
    void removeFromDeque(int randomIndex); // Remove an element from deque at specified index
    int FindProcessIndex(int PID); // Find index of a process in the processes vector
    int FindReadyQueueIndex(int PID); // Find index of a process in the ready queue
    int FindChildIndex(const Process& process, int childPID); // Find index of a child process
    bool IsDiskValid(int diskNumber); // Check if disk number is valid
    bool IsRunning(); // Check if any process is currently running
    // std::string getStatus(Process process); // Get status of a process
};

#endif