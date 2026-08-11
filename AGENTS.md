# cpu-task-handler agent instructions

This repository contains a C++17 command-line simulation of an operating
system CPU scheduler. Keep headers in `include/`, implementations in `src/`,
and business logic out of `main.cpp`.

The core scheduler uses non-preemptive priority scheduling. Higher-priority
processes run first, with PID (arrival order) breaking ties. The simulation
advances in 100 ms intervals and reports its execution timeline, memory use,
and final turnaround statistics.

Build with CMake and enable compiler warnings. Do not add external
dependencies, a GUI, or real multithreading.
