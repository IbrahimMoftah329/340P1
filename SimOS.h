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

struct FileReadRequest
{
    int  PID{0};
    std::string fileName{""};
};

struct MemoryItem
{
    unsigned long long pageNumber;
    unsigned long long frameNumber;
    int PID;
};

enum class Status {
  running,
  ready,
  waiting,
  zombie,
  terminated
};

struct Process {
    int PID;
    int parentPID;
    Status status;
    std::deque<int> children;
};

struct Disk {
    int PID;
    std::deque<FileReadRequest> ioQueue;
};

using MemoryUsage = std::vector<MemoryItem>;

constexpr int NO_PROCESS{ 0 };

class SimOS {
public:
    SimOS(int numberOfDisks, unsigned long long amountOfRAM, unsigned int pageSize);

    void NewProcess();
    void SimFork();
    void SimExit();
    void SimWait();
    void TimerInterrupt();
    void DiskReadRequest(int diskNumber, std::string fileName);
    void DiskJobCompleted(int diskNumber);
    void AccessMemoryAddress(unsigned long long address);

    int GetCPU();
    std::deque<int> GetReadyQueue();
    MemoryUsage GetMemory();
    FileReadRequest GetDisk(int diskNumber);
    std::deque<FileReadRequest> GetDiskQueue(int diskNumber);
    std::vector<Process> GetAllProcesses();
    void printProcess(const Process& process);

private:

    const int numberOfDisks;
    const unsigned int pageSize;
    std::deque<Process> readyQueue;
    std::vector<Process> processes;
    std::vector<Disk> disks;
    std::vector<bool> memoryMap;
    MemoryUsage memory;
    std::deque<MemoryItem> lruQueue;
    int nextPID;
    int runningPID;

    void ReleaseMemory(int PID);
    void CascadeTerminate(int PID);
    void removeFromDeque(int randomIndex);
    int FindProcessIndex(int PID);
    int FindReadyQueueIndex(int PID);
    int FindChildIndex(const Process& process, int childPID);
    bool IsDiskValid(int diskNumber);
    bool IsRunning();
    std::string getStatus(Process process);
};

#endif