# cpu-task-handler



Simulate how an operating system runs processes.

Chrome
Spotify
Discord
VS Code



Give each

priority
runtime
memory

Then schedule them.

You'll learn queues and scheduling algorithms.


I can help you break down this project into manageable prompts for Claude Code! Looking at the README, this is a CPU task scheduler simulator. Here's how to structure it:

## Understanding the Project

The project needs to:
1. Model processes (Chrome, Spotify, Discord, VS Code) with properties like priority and memory
2. Assign runtime/memory allocation to each
3. Implement scheduling algorithms (likely FIFO, priority queue, round-robin, etc.)
4. Simulate how the OS schedules and runs these tasks

## Recommended Breakdown for Claude Code

### Phase 1: Core Data Structures
**Prompt Strategy:** Start with the foundation
```
"Create a C++ program with the following components:
- A Process struct/class with: name, priority, memory_required, runtime_duration, process_id
- Define priority levels (HIGH, MEDIUM, LOW)
- Create a ProcessList/queue to hold multiple processes
Include comments explaining each component's purpose."
```

### Phase 2: Process Management
**Prompt Strategy:** Add initialization logic
```
"Add functionality to:
- Create and initialize 4 processes: Chrome, Spotify, Discord, VS Code with realistic values
  (e.g., Chrome: HIGH priority, 512MB, 5000ms runtime)
- Display process details in a readable format
- Add getters/setters for process properties"
```

### Phase 3: Scheduling Algorithm
**Prompt Strategy:** Implement the core logic
```
"Implement a priority queue-based CPU scheduler:
- Sort processes by priority (higher priority runs first)
- Add a method to schedule processes
- Track which process is currently running
- Handle process completion
- Use a time-based simulation with 100ms time intervals"
```

### Phase 4: Simulation & Output
**Prompt Strategy:** Create the runtime loop
```
"Add a simulation loop that:
- Allocates memory to each process based on priority
- Runs the scheduler
- Prints a timeline showing which process runs at each time interval
- Shows memory usage and process state changes
- Displays final statistics (total runtime, efficiency metrics)"
```

## Tips for Working with Claude Code:

1. **Be specific about data structures** — specify exact member variables, not just "store priority"
2. **Include example output** — show what you want the console output to look like
3. **Progressive enhancement** — get Phase 1 working, then build on it
4. **Request code organization** — ask for separate files (scheduler.h, process.h) if you want a clean structure
5. **Ask for comments** — especially helpful for understanding algorithm choices

Would you like me to write out complete prompts for any of these phases, or help you think through the specific scheduling algorithm you want to implement (priority queue, round-robin, etc.)?****
