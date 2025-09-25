# SetMonitorDisplayAreaPosition function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Sets the horizontal or vertical position of a monitor's display area.

Increasing the horizontal position moves the display area toward the right side of the screen; decreasing it moves the display area toward the left. Increasing the vertical position moves the display area toward the top of the screen; decreasing it moves the display area toward the bottom.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `ptPositionType` [in]

A member of the [MC_POSITION_TYPE](https://learn.microsoft.com/windows/win32/api/highlevelmonitorconfigurationapi/ne-highlevelmonitorconfigurationapi-mc_position_type) enumeration, specifying whether to set the horizontal position or the vertical position.

### `dwNewPosition` [in]

Horizontal or vertical position. To get the minimum and maximum position, call [GetMonitorDisplayAreaPosition](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitordisplayareaposition).

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_DISPLAY_AREA_POSITION flag.

This function takes about 50 milliseconds to return.

The horizontal and vertical position are continuous monitor settings. For more information, see [Using the High-Level Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/using-the-high-level-monitor-configuration-functions).

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)