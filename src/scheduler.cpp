#include "scheduler.h"

#include <algorithm>
#include <stdexcept>
#include <utility>

Scheduler::Scheduler(std::vector<Process> processes)
    : processes_(std::move(processes)) {
    // Stable priority/PID ordering models a FIFO queue within each priority.
    std::stable_sort(processes_.begin(), processes_.end(),
                     [](const Process& left, const Process& right) {
                         if (left.priority() != right.priority()) {
                             return left.priority() < right.priority();
                         }
                         return left.pid() < right.pid();
                     });
}

bool Scheduler::has_work() const {
    return std::any_of(processes_.begin(), processes_.end(),
                       [](const Process& process) {
                           return process.state() != State::TERMINATED;
                       });
}

SimulationStep Scheduler::step() {
    if (!has_work()) {
        throw std::logic_error("cannot step a completed simulation");
    }

    if (current_process_ == no_process) {
        current_process_ = select_next_process();
    }

    if (current_process_ == no_process) {
        SimulationStep idle_step{current_time_, time_interval, "Idle", 0, false};
        current_time_ += time_interval;
        cpu_idle_time_ += time_interval;
        return idle_step;
    }

    Process& process = processes_[current_process_];
    process.set_state(State::RUNNING);

    const int duration = std::min(time_interval, process.remaining_time());
    SimulationStep result{current_time_, duration, process.name(),
                          calculate_memory_in_use(), false};

    process.run_for(duration);
    current_time_ += duration;

    if (process.remaining_time() == 0) {
        process.set_state(State::TERMINATED);
        process.set_completion_time(current_time_);
        result.process_completed = true;
        current_process_ = no_process;
    }

    return result;
}

int Scheduler::total_time() const { return current_time_; }
int Scheduler::cpu_idle_time() const { return cpu_idle_time_; }

const std::vector<Process>& Scheduler::processes() const {
    return processes_;
}

std::size_t Scheduler::select_next_process() const {
    for (std::size_t index = 0; index < processes_.size(); ++index) {
        if (processes_[index].state() == State::READY) {
            return index;
        }
    }
    return no_process;
}

int Scheduler::calculate_memory_in_use() const {
    int total_memory = 0;
    for (const Process& process : processes_) {
        if (process.state() != State::TERMINATED) {
            total_memory += process.memory_required();
        }
    }
    return total_memory;
}
