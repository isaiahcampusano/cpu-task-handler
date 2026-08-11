#include "process.h"
#include "scheduler.h"

#include <iostream>

int main() {
    std::vector<Process> processes = create_sample_processes();

    std::cout << "CPU Task Handler\n"
              << "================\n\n"
              << "Processes:\n";
    for (const Process& process : processes) {
        std::cout << "  " << process << '\n';
    }

    Scheduler scheduler(std::move(processes));

    std::cout << "\nSchedule (non-preemptive priority):\n";
    while (scheduler.has_work()) {
        const SimulationStep step = scheduler.step();
        std::cout << '[' << step.start_time << "] ms - Running: "
                  << step.process_name << " | Memory in use: "
                  << step.memory_in_use << " MB\n";
    }

    std::cout << "\nFinal statistics:\n"
              << "  Total simulation time: " << scheduler.total_time() << " ms\n"
              << "  CPU idle time: " << scheduler.cpu_idle_time() << " ms\n"
              << "  Per-process turnaround time:\n";

    for (const Process& process : scheduler.processes()) {
        // Every sample process arrives at time zero, so completion equals turnaround.
        std::cout << "    " << process.name() << ": "
                  << process.completion_time() << " ms\n";
    }

    return 0;
}
