#ifndef CPU_TASK_HANDLER_PROCESS_H
#define CPU_TASK_HANDLER_PROCESS_H

#include <iosfwd>
#include <string>
#include <vector>

enum class Priority {
    HIGH,
    MEDIUM,
    LOW
};

enum class State {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

class Process {
public:
    Process(int pid, std::string name, Priority priority,
            int memory_required, int burst_time);

    int pid() const;
    const std::string& name() const;
    Priority priority() const;
    int memory_required() const;
    int burst_time() const;
    int remaining_time() const;
    State state() const;
    int completion_time() const;

    void set_state(State state);
    void run_for(int duration);
    void set_completion_time(int completion_time);

private:
    int pid_;
    std::string name_;
    Priority priority_;
    int memory_required_;
    int burst_time_;
    int remaining_time_;
    State state_;
    int completion_time_;
};

class ProcessQueue {
public:
    void add_process(std::string name, Priority priority,
                     int memory_required, int burst_time);
    const std::vector<Process>& processes() const;
    std::vector<Process> take_processes();

private:
    std::vector<Process> processes_;
    int next_pid_ = 1;
};

std::vector<Process> create_sample_processes();
const char* to_string(Priority priority);
const char* to_string(State state);
std::ostream& operator<<(std::ostream& output, const Process& process);

#endif
