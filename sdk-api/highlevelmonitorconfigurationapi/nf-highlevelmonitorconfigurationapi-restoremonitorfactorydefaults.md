# RestoreMonitorFactoryDefaults function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Restores a monitor's settings to their factory defaults.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function restores all of the settings that are supported by the high-level monitor configuration functions. It might also restore settings that are available only through the low-level functions and are not supported by the high-level functions. The current value of each setting is changed to its factory default. The exact settings that change, and the default values of those settings, depend on the manufacturer. This function can also change the range of supported values for some settings.

If this function is supported, the [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) function returns the MC_CAPS_RESTORE_FACTORY_DEFAULTS flag.

This function takes about 5 seconds to return.

If [GetMonitorCapabilities](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcapabilities) returns the MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS flag, this function also enables all of the monitor settings that are supported by the high-level functions. It is sometimes possible for an application to disable certain settings by calling the low-level functions. It is also possible for the user to disable certain settings by adjusting settings on the monitor's physical control panel. If that happens, the setting can only be re-enabled through the control panel or by calling **RestoreMonitorFactoryDefaults**. It is not possible to disable any settings by using the high-level functions.

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)

[RestoreMonitorFactoryColorDefaults](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-restoremonitorfactorycolordefaults)