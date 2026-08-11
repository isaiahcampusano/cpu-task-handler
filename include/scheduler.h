#ifndef CPU_TASK_HANDLER_SCHEDULER_H
#define CPU_TASK_HANDLER_SCHEDULER_H

#include "process.h"

#include <cstddef>
#include <string>
#include <vector>

struct SimulationStep {
    int start_time = 0;
    int duration = 0;
    std::string process_name;
    int memory_in_use = 0;
    bool process_completed = false;
};

class Scheduler {
public:
    static constexpr int time_interval = 100;

    explicit Scheduler(std::vector<Process> processes);

    bool has_work() const;
    SimulationStep step();
    int total_time() const;
    int cpu_idle_time() const;
    const std::vector<Process>& processes() const;

private:
    static constexpr std::size_t no_process = static_cast<std::size_t>(-1);

    std::size_t select_next_process() const;
    int calculate_memory_in_use() const;

    std::vector<Process> processes_;
    std::size_t current_process_ = no_process;
    int current_time_ = 0;
    int cpu_idle_time_ = 0;
};

#endif
