# GetMonitorContrast function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Retrieves a monitor's minimum, maximum, and current contrast settings.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `pdwMinimumContrast` [out]

Receives the monitor's minimum contrast.

### `pdwCurrentContrast` [out]

Receives the monitor's current contrast.

### `pdwMaximumContrast` [out]

Receives the monitor's maximum contrast.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_CONTRAST flag.

This function takes about 40 milliseconds to return.

The brightness setting is a continuous monitor setting. For more information, see [Using the High-Level Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/using-the-high-level-monitor-configuration-functions).

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)