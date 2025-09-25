# GetMonitorRedGreenOrBlueDrive function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Retrieves a monitor's red, green, or blue drive value.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `dtDriveType` [in]

A member of the [MC_DRIVE_TYPE](https://learn.microsoft.com/windows/win32/api/highlevelmonitorconfigurationapi/ne-highlevelmonitorconfigurationapi-mc_drive_type) enumeration, specifying whether to retrieve the red, green, or blue drive value.

### `pdwMinimumDrive` [out]

Receives the minimum red, green, or blue drive value.

### `pdwCurrentDrive` [out]

Receives the current red, green, or blue drive value.

### `pdwMaximumDrive` [out]

Receives the maximum red, green, or blue drive value.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Drive settings are generally used to adjust the monitor's white point. *Drive* and *black level* are different names for the same monitor setting. If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_RED_GREEN_BLUE_DRIVE flag.

This function takes about 40 milliseconds to return.

The drive settings are continuous monitor settings. For more information, see [Using the High-Level Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/using-the-high-level-monitor-configuration-functions).

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)