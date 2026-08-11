# CPU Task Handler

simulates the operating system’s CPU scheduler—the part of the OS that chooses which app or process gets to use the processor first based on priority, then tracks its runtime and memory use.

## Install and run

Windows PowerShell:

```powershell
winget install --exact --id BrechtSanders.WinLibs.POSIX.UCRT --accept-package-agreements --accept-source-agreements
```

Restart VS Code after installation, open the project folder, and run:

```powershell
cmake -S . -B build
cmake --build build
.\build\cpu-task-handler.exe
```

## Controls

- Run the simulation: `.\build\cpu-task-handler.exe`
- Rebuild after changes: `cmake --build build`
- Stop a running command: `Ctrl+C`
- Change sample processes: edit `create_sample_processes()` in `src/process.cpp`
- Change the 100 ms interval: edit `time_interval` in `include/scheduler.h`

## Roadmap

- Add round-robin scheduling and a selectable scheduling mode
- Add process arrival and waiting times
- Add automated scheduler tests
- Support configurable input and CSV timeline export

## Ecosystem

- C++17
- CMake
- GCC/MinGW on Windows
- No external runtime dependencies
