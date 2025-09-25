# GetNumberOfPhysicalMonitorsFromHMONITOR function

## Description

Retrieves the number of physical monitors associated with an **HMONITOR** monitor handle. Call this function before calling [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor).

## Parameters

### `hMonitor` [in]

A monitor handle. Monitor handles are returned by several Multiple Display Monitor functions, including [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) and [MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow), which are part of the graphics device interface (GDI).

### `pdwNumberOfPhysicalMonitors` [out]

Receives the number of physical monitors associated with the monitor handle.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor)

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)