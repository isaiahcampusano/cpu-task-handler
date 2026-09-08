# cpu-task-handler agent instructions

This repository contains a C++17 command-line simulation of an operating
system CPU scheduler. Keep headers in `include/`, implementations in `src/`,
and business logic out of `main.cpp`.

The core scheduler uses non-preemptive priority scheduling. Higher-priority
processes run first, with PID (arrival order) breaking ties. The simulation
advances in 100 ms intervals and reports its execution timeline, memory use,
and final turnaround statistics.

Build with CMake and enable compiler warnings. Do not add external
dependencies or real multithreading. Keep the optional GitHub Pages demo in
`site/`; it must remain a dependency-free static visualization, visibly label
all generated values as simulated, and never access or claim to access live
system telemetry. Do not add a GUI framework or backend service.
