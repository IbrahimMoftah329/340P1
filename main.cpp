/*
CSCI340 Spring 2024
Project 1
Ibrahim Moftah
*/

#include "SimOS.h"
#include<deque>

// int main() {
// 	// g++  -std=c++17  *.cpp  -o os_test
//     SimOS simOS(2, 1024, 64); // 2 disks, 1024 memory, 64 page size

//     // Test NewProcess
//     simOS.NewProcess();
//     int cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     simOS.NewProcess();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     simOS.NewProcess();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after creating 3 processes: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     std::vector<Process> allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimFork
//     simOS.SimFork();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after forking: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimFork
//     simOS.SimFork();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after forking: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimExit
//     simOS.SimExit();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after exiting process: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     simOS.NewProcess();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;

//     simOS.NewProcess();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;

//     simOS.NewProcess();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;

//     // adding 3 new processes
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after creating 3 mew processes: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test TimerInterrupt
//     simOS.TimerInterrupt();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after timer interrupt: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimWait
//     simOS.SimWait();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after waiting: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimFork
//     simOS.SimFork();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after forking: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimFork
//     simOS.SimFork();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after forking: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimWait
//     simOS.SimWait();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after waiting: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     simOS.TimerInterrupt();
//     simOS.TimerInterrupt();
//     simOS.TimerInterrupt();
//     simOS.TimerInterrupt();

//     // Test moving to process 10 running
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after moving to process 10 running: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimExit
//     simOS.SimExit();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after after exiting process: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     simOS.TimerInterrupt();
//     simOS.TimerInterrupt();
//     simOS.TimerInterrupt();

//     // Test moving to process 9 running
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after moving to process 9 running: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimExit
//     simOS.SimExit();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after after exiting process: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test SimWait
//     simOS.SimWait();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after waiting: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test DiskReadRequest
//     simOS.DiskReadRequest(0, "file1.txt");
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after DiskReadRequest: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test DiskReadRequest
//     simOS.DiskReadRequest(0, "file2.txt");
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after DiskReadRequest: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     FileReadRequest diskRequest = simOS.GetDisk(0);
//     std::cout << "Disk 0 request: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

//     // Test DiskJobCompleted
//     simOS.DiskJobCompleted(0);
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after DiskJobCompleted: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     diskRequest = simOS.GetDisk(0);
//     std::cout << "Disk 0 request after job completion: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

//     // Test AccessMemoryAddress
//     simOS.AccessMemoryAddress(130);
//     MemoryUsage memoryUsage = simOS.GetMemory();
//     std::cout << "Memory Usage after accessing address 128: ";
//     for (const auto& item : memoryUsage) {
//         std::cout << "(" << item.pageNumber << ", " << item.frameNumber << ", " << item.PID << ") ";
//     }
//     std::cout << std::endl;

//     // Test exit memory clearing
//     simOS.SimExit();
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after exit memory clearing: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     // Test 
//     memoryUsage = simOS.GetMemory();
//     std::cout << "Memory Usage after accessing address 128: ";
//     for (const auto& item : memoryUsage) {
//         std::cout << "(" << item.pageNumber << ", " << item.frameNumber << ", " << item.PID << ") ";
//     }
//     std::cout << std::endl;

//     // Test DiskJobCompleted
//     simOS.DiskJobCompleted(0);
//     cpu = simOS.GetCPU();
//     std::cout << cpu << std::endl;
//     std::cout << "Ready Queue after DiskJobCompleted: ";
//     for (int pid : simOS.GetReadyQueue()) {
//         std::cout << pid << " ";
//     }
//     std::cout << std::endl;

//     // Assuming SimOS object is named simOS
//     allProcesses = simOS.GetAllProcesses();

//     // Loop through all processes
//     for (const auto& process : allProcesses) {
//         // Access process properties as needed
//         simOS.printProcess(process);
//     }

//     diskRequest = simOS.GetDisk(0);
//     std::cout << "Disk 0 request after job completion: PID=" << diskRequest.PID << ", File=" << diskRequest.fileName << std::endl;

//     return 0;
// }

int main()
{
	SimOS sim{ 3, 1000, 10 };
	bool allTestsClean{ true };

	if (sim.GetCPU() != NO_PROCESS)
	{
		allTestsClean = false;
		std::cout << "Test on the line 9 fails!" << std::endl;
	}

	sim.NewProcess();
	if (sim.GetCPU() != 1)
	{
		allTestsClean = false;
		std::cout << "Test on the line 16 fails!" << std::endl;
	}

	sim.DiskReadRequest(0, "file1.txt");
	if (sim.GetCPU() != NO_PROCESS)
	{
		allTestsClean = false;
		std::cout << "Test on the line 23 fails!" << std::endl;
	}

	FileReadRequest request{ sim.GetDisk(0) };
	if (request.PID != 1 || request.fileName != "file1.txt")
	{
		allTestsClean = false;
		std::cout << "Test on the line 30 fails!" << std::endl;
	}

	std::deque<FileReadRequest> ioQueue0{ sim.GetDiskQueue(0) };
	if (ioQueue0.size() != 0)
	{
		allTestsClean = false;
		std::cout << "Test on the line 37 fails!" << std::endl;
	}

	sim.DiskJobCompleted(0);
	request = sim.GetDisk(0);
	if (request.PID != NO_PROCESS || request.fileName != "")
	{
		allTestsClean = false;
		std::cout << "Test on the line 45 fails!" << std::endl;
	}

	if (sim.GetCPU() != 1)
	{
		allTestsClean = false;
		std::cout << "Test on the line 51 fails!" << std::endl;
	}

	std::deque<int> readyQueue{ sim.GetReadyQueue() };
	if (readyQueue.size() != 0)
	{
		allTestsClean = false;
		std::cout << "Test on the line 58 fails!" << std::endl;
	}

	sim.SimFork();
	readyQueue = sim.GetReadyQueue();
	if (readyQueue[0] != 2)
	{
		allTestsClean = false;
		std::cout << "Test on the line 66 fails!" << std::endl;
	}

	sim.TimerInterrupt();
	readyQueue = sim.GetReadyQueue();
	if (sim.GetCPU() != 2 || readyQueue[0] != 1)
	{
		allTestsClean = false;
		std::cout << "Test on the line 74 fails!" << std::endl;
	}

	sim.SimExit();
	readyQueue = sim.GetReadyQueue();
	if (sim.GetCPU() != 1 || readyQueue.size() != 0)
	{
		allTestsClean = false;
		std::cout << "Test on the line 82 fails!" << std::endl;
	}

	sim.AccessMemoryAddress(140);
	MemoryUsage ram{ sim.GetMemory() };
	if (ram[0].pageNumber != 14 || ram[0].PID != 1)
	{
		allTestsClean = false;
		std::cout << "Test on the line 90 fails!" << std::endl;
	}

	sim.SimWait();
	if (sim.GetCPU() != 1)
	{
		allTestsClean = false;
		std::cout << "Test on the line 97 fails!" << std::endl;
	}

	sim.SimExit();
	ram = sim.GetMemory();
	if (sim.GetCPU() != NO_PROCESS || ram.size() != 0)
	{
		allTestsClean = false;
		std::cout << "Test on the line 105 fails!" << std::endl;
	}

	if (allTestsClean)
		std::cout << "These preliminary tests are passed" << std::endl;

	return 0;
}