# DestroyPhysicalMonitors function

## Description

Closes an array of physical monitor handles. Call this function to close an array of monitor handles obtained from the [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9) function.

## Parameters

### `dwPhysicalMonitorArraySize` [in]

Number of elements in the *pPhysicalMonitorArray* array.

### `pPhysicalMonitorArray` [in]

Pointer to an array of [PHYSICAL_MONITOR](https://learn.microsoft.com/windows/win32/api/physicalmonitorenumerationapi/ns-physicalmonitorenumerationapi-physical_monitor) structures.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[DestroyPhysicalMonitor Function](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-destroyphysicalmonitor)

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)