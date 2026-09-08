# CPU Task Handler

CPU Task Handler is a C++17 simulation of the part of an operating system that chooses which process gets CPU time. It orders sample processes by priority, advances them in 100 ms intervals, and reports runtime and memory statistics.

The repository also includes a static, Windows Task Manager-inspired [performance dashboard](site/index.html). The dashboard is a visual demo: every displayed CPU, memory, disk, and network value is generated in the browser and is **not live system telemetry**.

## Run the C++ scheduler

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

## Preview the dashboard

Open `site/index.html` directly in a browser. No installation, backend, account, or device permission is required.

The orange **Simulated Demo Data — Not Live System Telemetry** notice stays visible while the page runs. Browsers cannot use this static page to inspect the host computer, and this project intentionally does not include a local telemetry server.

## Publish with GitHub Pages

The `Deploy dashboard to Pages` workflow publishes only the contents of `site/` whenever a change reaches `main`. Before the first deployment:

1. Open **Settings → Pages** in the GitHub repository.
2. Set **Source** to **GitHub Actions**.
3. Merge or push a dashboard change to `main`, or manually run the deployment from the **Actions** tab.

The published dashboard will be available at <https://isaiahcampusano.github.io/cpu-task-handler/> after the workflow completes.

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
- Static HTML, CSS, and JavaScript dashboard
