# CPU Task Handler

CPU Task Handler is a C++17 simulation of the part of an operating system that chooses which process gets CPU time. It orders sample processes by priority, advances them in 100 ms intervals, and reports runtime and memory statistics.

The repository also includes a static, Windows Task Manager-inspired [performance dashboard](https://isaiahcampusano.github.io/cpu-task-handler/). The dashboard is a visual demo: every displayed CPU, memory, disk, and network value is generated in the browser and is **not live system telemetry**.


<img width="1067" height="575" alt="image" src="https://github.com/user-attachments/assets/a7d69fce-3615-467e-8ce9-8e77d23bbd83" />

## Run the C++ scheduler

Windows PowerShell:

```powershell
winget install --exact --id Kitware.CMake --accept-package-agreements --accept-source-agreements
winget install --exact --id BrechtSanders.WinLibs.POSIX.UCRT --accept-package-agreements --accept-source-agreements
```

Restart VS Code after installing CMake and the compiler, open the project folder, and run:

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

GitHub Pages is configured to use GitHub Actions. The `Deploy dashboard to Pages` workflow publishes only the contents of `site/` whenever a dashboard or deployment-workflow change reaches `main`.

To redeploy without making a change, manually run **Deploy dashboard to Pages** from the repository's **Actions** tab. Do not switch the Pages source to branch publishing; the workflow maps `site/` to the site's root URL.

The dashboard is live at <https://isaiahcampusano.github.io/cpu-task-handler/>.

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
