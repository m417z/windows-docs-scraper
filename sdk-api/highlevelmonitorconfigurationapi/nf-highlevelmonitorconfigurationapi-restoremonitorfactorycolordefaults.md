# RestoreMonitorFactoryColorDefaults function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Restores a monitor's color settings to their factory defaults.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function potentially changes the current value of the monitor's brightness, contrast, color temperature, drive, and gain. The current value of each setting is changed to its factory default. The default settings depend on the manufacturer. This function can also change the range of supported values for each of these settings. The function does not enable any monitor settings that were disabled.

If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS flag. This function takes about 5 seconds to return.

This function might reset monitor settings that are not accessible through the high-level monitor configuration functions. Whether this occurs depends on the specific model of monitor.

The following settings are not affected by this function:

* Display area size
* Display area position
* Capabilities flags

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)

[RestoreMonitorFactoryDefaults](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-restoremonitorfactorydefaults)