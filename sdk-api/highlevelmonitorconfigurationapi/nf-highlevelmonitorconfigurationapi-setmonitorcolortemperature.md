# SetMonitorColorTemperature function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Sets a monitor's color temperature.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `ctCurrentColorTemperature` [in]

Color temperature, specified as a member of the [MC_COLOR_TEMPERATURE](https://learn.microsoft.com/windows/win32/api/highlevelmonitorconfigurationapi/ne-highlevelmonitorconfigurationapi-mc_color_temperature) enumeration.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_COLOR_TEMPERATURE flag. The **GetMonitorCapabilities** function also returns the range of color temperatures that the monitor supports. The *ctCurrentColorTemperature* parameter must correspond to one of these values.

Changing the color temperature changes the monitor's white point. It can also change the current drive and gain settings. To get the new drive and gain settings, call [GetMonitorRedGreenOrBlueDrive](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorredgreenorbluedrive) and [GetMonitorRedGreenOrBlueGain](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorredgreenorbluegain), respectively.

This function takes from 50 to 90 milliseconds to return.

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)