#include "process.h"

#include <algorithm>
#include <ostream>
#include <stdexcept>
#include <utility>

Process::Process(int pid, std::string name, Priority priority,
                 int memory_required, int burst_time)
    : pid_(pid),
      name_(std::move(name)),
      priority_(priority),
      memory_required_(memory_required),
      burst_time_(burst_time),
      remaining_time_(burst_time),
      state_(State::READY),
      completion_time_(-1) {
    if (pid <= 0 || memory_required < 0 || burst_time <= 0) {
        throw std::invalid_argument("process values must be positive");
    }
}

int Process::pid() const { return pid_; }
const std::string& Process::name() const { return name_; }
Priority Process::priority() const { return priority_; }
int Process::memory_required() const { return memory_required_; }
int Process::burst_time() const { return burst_time_; }
int Process::remaining_time() const { return remaining_time_; }
State Process::state() const { return state_; }
int Process::completion_time() const { return completion_time_; }

void Process::set_state(State state) { state_ = state; }

void Process::run_for(int duration) {
    if (duration <= 0) {
        throw std::invalid_argument("run duration must be positive");
    }
    remaining_time_ = std::max(0, remaining_time_ - duration);
}

void Process::set_completion_time(int completion_time) {
    completion_time_ = completion_time;
}

void ProcessQueue::add_process(std::string name, Priority priority,
                               int memory_required, int burst_time) {
    // The queue owns PID assignment so IDs reflect process arrival order.
    processes_.emplace_back(next_pid_++, std::move(name), priority,
                            memory_required, burst_time);
}

const std::vector<Process>& ProcessQueue::processes() const {
    return processes_;
}

std::vector<Process> ProcessQueue::take_processes() {
    return std::move(processes_);
}

std::vector<Process> create_sample_processes() {
    ProcessQueue queue;
    queue.add_process("Chrome", Priority::HIGH, 512, 5000);
    queue.add_process("VS Code", Priority::HIGH, 300, 6000);
    queue.add_process("Discord", Priority::MEDIUM, 256, 4000);
    queue.add_process("Spotify", Priority::MEDIUM, 128, 3000);
    return queue.take_processes();
}

const char* to_string(Priority priority) {
    switch (priority) {
        case Priority::HIGH:
            return "HIGH";
        case Priority::MEDIUM:
            return "MEDIUM";
        case Priority::LOW:
            return "LOW";
    }
    return "UNKNOWN";
}

const char* to_string(State state) {
    switch (state) {
        case State::READY:
            return "READY";
        case State::RUNNING:
            return "RUNNING";
        case State::WAITING:
            return "WAITING";
        case State::TERMINATED:
            return "TERMINATED";
    }
    return "UNKNOWN";
}

std::ostream& operator<<(std::ostream& output, const Process& process) {
    output << "PID " << process.pid() << " | " << process.name()
           << " | Priority: " << to_string(process.priority())
           << " | Memory: " << process.memory_required() << " MB"
           << " | Runtime: " << process.burst_time() << " ms"
           << " | State: " << to_string(process.state());
    return output;
}
