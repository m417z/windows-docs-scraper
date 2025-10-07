# GetCurrentMonitorTopologyId function

Retrieves the ID of the current monitor topology.

## Return value

Type: **UINT**

ID of the current monitor topology.

## Remarks

> [!TIP]
> At this time, this function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`User32.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

The value returned from **GetCurrentMonitorTopologyId** will be different any time the monitor topology changes. It is also guaranteed to never return **INVALID_MONITOR_TOPOLOGY_ID**. The monitor topology changes when:
- A monitor is added or removed.
- The number of monitors can be queried using [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) with **SM_CMONITORS**.
- A monitor’s display rectangle changes.
- A monitor’s rectangle can be obtained by calling [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) and then checking the value of rcMonitor on the [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) returned.
- A monitor’s work area rectangle changes
- A monitor’s work area can be obtained by calling [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) and then checking the value of rcWork on the [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) returned.
- A monitor’s DPI changes
- The DPI of a monitor can be obtained by calling [GetDpiForMonitor](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/nf-shellscalingapi-getdpiformonitor).
- A monitor’s handle changes
- The monitor’s handle can be obtained with [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors)
-A monitor’s name changes
- The name of a monitor can be obtained with [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) using the [MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure. Each time the topology changes, the current monitor topology ID will change. In other words, topologies with two different IDs may have identical topologies.
Note that the items that define a topology may expand in the future, but it is guaranteed that items will not be removed.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | User32.dll |