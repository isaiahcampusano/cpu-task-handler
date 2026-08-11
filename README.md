# CPU Task Handler

A C++17 command-line simulation showing how an operating system schedules
processes. Chrome, VS Code, Discord, and Spotify are modeled with priorities,
memory footprints, and CPU burst times.

The scheduler uses **non-preemptive priority scheduling**: high-priority
processes run first, and PID/arrival order breaks priority ties. Each process
runs to completion while the simulation reports progress in 100 ms intervals.

## Build and run

```sh
cmake -S . -B build
cmake --build build
./build/cpu-task-handler
```

On multi-config generators such as Visual Studio, run the executable from the
selected configuration directory (for example, `build/Debug`).

## Sample processes

| Process | Priority | Memory | Runtime |
| --- | --- | ---: | ---: |
| Chrome | High | 512 MB | 5000 ms |
| VS Code | High | 300 MB | 6000 ms |
| Discord | Medium | 256 MB | 4000 ms |
| Spotify | Medium | 128 MB | 3000 ms |

The final report includes total simulation time, CPU idle time, and each
process's turnaround time.
