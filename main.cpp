/*
CSCI340 Spring 2024
Project 1
Ibrahim Moftah
*/

#include "SimOS.h"

int main() {
    SimOS simOS(2, 1024, 64); // 2 disks, 1024 memory, 64 page size

    // Test NewProcess
    simOS.NewProcess();
    int cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    simOS.NewProcess();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    simOS.NewProcess();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after creating 3 processes: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    std::vector<Process> allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimFork
    simOS.SimFork();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after forking: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimFork
    simOS.SimFork();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after forking: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimExit
    simOS.SimExit();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after exiting process: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    simOS.NewProcess();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;

    simOS.NewProcess();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;

    simOS.NewProcess();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;

    // adding 3 new processes
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after creating 3 mew processes: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test TimerInterrupt
    simOS.TimerInterrupt();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after timer interrupt: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimWait
    simOS.SimWait();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after waiting: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimFork
    simOS.SimFork();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after forking: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimFork
    simOS.SimFork();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after forking: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimWait
    simOS.SimWait();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after waiting: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    simOS.TimerInterrupt();
    simOS.TimerInterrupt();
    simOS.TimerInterrupt();
    simOS.TimerInterrupt();

    // Test moving to process 10 running
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after moving to process 10 running: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimExit
    simOS.SimExit();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after after exiting process: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    simOS.TimerInterrupt();
    simOS.TimerInterrupt();
    simOS.TimerInterrupt();

    // Test moving to process 9 running
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after moving to process 9 running: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimExit
    simOS.SimExit();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after after exiting process: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test SimWait
    simOS.SimWait();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after waiting: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test DiskReadRequest
    simOS.DiskReadRequest(0, "file1.txt");
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after DiskReadRequest: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test DiskReadRequest
    simOS.DiskReadRequest(0, "file2.txt");
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after DiskReadRequest: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    FileReadRequest diskRequest = simOS.GetDisk(0);
    std::cout << "Disk 0 request: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

    // Test DiskJobCompleted
    simOS.DiskJobCompleted(0);
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after DiskJobCompleted: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    diskRequest = simOS.GetDisk(0);
    std::cout << "Disk 0 request after job completion: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

    // Test AccessMemoryAddress
    simOS.AccessMemoryAddress(130);
    MemoryUsage memoryUsage = simOS.GetMemory();
    std::cout << "Memory Usage after accessing address 128: ";
    for (const auto& item : memoryUsage) {
        std::cout << "(" << item.pageNumber << ", " << item.frameNumber << ", " << item.PID << ") ";
    }
    std::cout << std::endl;

    // Test exit memory clearing
    simOS.SimExit();
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after exit memory clearing: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    // Test 
    memoryUsage = simOS.GetMemory();
    std::cout << "Memory Usage after accessing address 128: ";
    for (const auto& item : memoryUsage) {
        std::cout << "(" << item.pageNumber << ", " << item.frameNumber << ", " << item.PID << ") ";
    }
    std::cout << std::endl;

    // Test DiskJobCompleted
    simOS.DiskJobCompleted(0);
    cpu = simOS.GetCPU();
    std::cout << cpu << std::endl;
    std::cout << "Ready Queue after DiskJobCompleted: ";
    for (int pid : simOS.GetReadyQueue()) {
        std::cout << pid << " ";
    }
    std::cout << std::endl;

    // Assuming SimOS object is named simOS
    allProcesses = simOS.GetAllProcesses();

    // Loop through all processes
    for (const auto& process : allProcesses) {
        // Access process properties as needed
        simOS.printProcess(process);
    }

    diskRequest = simOS.GetDisk(0);
    std::cout << "Disk 0 request after job completion: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

    return 0;
}