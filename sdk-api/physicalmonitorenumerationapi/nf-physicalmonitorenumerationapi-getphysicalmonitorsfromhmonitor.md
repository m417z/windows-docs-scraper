# GetPhysicalMonitorsFromHMONITOR function

## Description

Retrieves the physical monitors associated with an **HMONITOR** monitor handle.

## Parameters

### `hMonitor` [in]

A monitor handle. Monitor handles are returned by several Multiple Display Monitor functions, including [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) and [MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow), which are part of the graphics device interface (GDI).

### `dwPhysicalMonitorArraySize` [in]

Number of elements in *pPhysicalMonitorArray*. To get the required size of the array, call [GetNumberOfPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getnumberofphysicalmonitorsfromhmonitor).

### `pPhysicalMonitorArray` [out]

Pointer to an array of [PHYSICAL_MONITOR](https://learn.microsoft.com/windows/win32/api/physicalmonitorenumerationapi/ns-physicalmonitorenumerationapi-physical_monitor) structures. The caller must allocate the array.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A single **HMONITOR** handle can be associated with more than one physical monitor. This function returns a handle and a text description for each physical monitor.

When you are done using the monitor handles, close them by passing the *pPhysicalMonitorArray* array to the [DestroyPhysicalMonitors](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-destroyphysicalmonitors) function.

#### Examples

```cpp

HMONITOR hMonitor = NULL;
DWORD cPhysicalMonitors;
LPPHYSICAL_MONITOR pPhysicalMonitors = NULL;

// Get the monitor handle.
hMonitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY);

// Get the number of physical monitors.
BOOL bSuccess = GetNumberOfPhysicalMonitorsFromHMONITOR(
  hMonitor,
  &cPhysicalMonitors
   );

if (bSuccess)
{
    // Allocate the array of PHYSICAL_MONITOR structures.
    pPhysicalMonitors = (LPPHYSICAL_MONITOR)malloc(
        cPhysicalMonitors* sizeof(PHYSICAL_MONITOR));

    if (pPhysicalMonitors != NULL)
    {
        // Get the array.
        bSuccess = GetPhysicalMonitorsFromHMONITOR(
            hMonitor, cPhysicalMonitors, pPhysicalMonitors);

       // Use the monitor handles (not shown).

        // Close the monitor handles.
        bSuccess = DestroyPhysicalMonitors(
            cPhysicalMonitors,
            pPhysicalMonitors);

        // Free the array.
        free(pPhysicalMonitors);
    }
}

```

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)