# GetMonitorCapabilities function

## Description

> [!WARNING]
> The physical monitor configuration functions work using the VESA Monitor Control Command Set (MCCS) standard over an I2C interface. Many monitors don't fully implement that standard; so your use of these commands might result in undefined monitor behavior. We don't recommend using these functions for arbitrary monitors without physically validating that they work as intended.

Retrieves the configuration capabilities of a monitor. Call this function to find out which high-level monitor configuration functions are supported by the monitor.

## Parameters

### `hMonitor` [in]

Handle to a physical monitor. To get the monitor handle, call [GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor) or [GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9).

### `pdwMonitorCapabilities` [out]

Receives a bitwise **OR** of capabilities flags. See Remarks.

### `pdwSupportedColorTemperatures` [out]

Receives a bitwise **OR** of color temperature flags. See Remarks.

## Return value

If the function succeeds, the return value is **TRUE**. If the function fails, the return value is **FALSE**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The function fails if the monitor does not support DDC/CI.

## Remarks

The capabilities flags returned in *pdwMonitorCapabilities* specify which high-level monitor configuration functions are supported by the monitor. They also specify how certain functions behave. The following capabilities flags are defined.

| Value | Description |
| --- | --- |
| **MC_CAPS_BRIGHTNESS** | The monitor supports the [GetMonitorBrightness](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorbrightness) and [SetMonitorBrightness](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitorbrightness) functions. |
| **MC_CAPS_COLOR_TEMPERATURE** | The monitor supports the [GetMonitorColorTemperature](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcolortemperature) and [SetMonitorColorTemperature](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitorcolortemperature) functions. |
| **MC_CAPS_CONTRAST** | The monitor supports the [GetMonitorContrast](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorcontrast) and [SetMonitorContrast](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitorcontrast) functions. |
| **MC_CAPS_DEGAUSS** | The monitor supports the [DegaussMonitor](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-degaussmonitor) function. |
| **MC_CAPS_DISPLAY_AREA_POSITION** | The monitor supports the [GetMonitorDisplayAreaPosition](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitordisplayareaposition) and [SetMonitorDisplayAreaPosition](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitordisplayareaposition) functions. |
| **MC_CAPS_DISPLAY_AREA_SIZE** | The monitor supports the [GetMonitorDisplayAreaSize](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitordisplayareasize) and [SetMonitorDisplayAreaSize](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitordisplayareasize) functions. |
| **MC_CAPS_MONITOR_TECHNOLOGY_TYPE** | The monitor supports the [GetMonitorTechnologyType](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitortechnologytype) function. |
| **MC_CAPS_NONE** | The monitor does not support any monitor settings. |
| **MC_CAPS_RED_GREEN_BLUE_DRIVE** | The monitor supports the [GetMonitorRedGreenOrBlueDrive](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorredgreenorbluedrive) and [SetMonitorRedGreenOrBlueDrive](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitorredgreenorbluedrive) functions. |
| **MC_CAPS_RED_GREEN_BLUE_GAIN** | The monitor supports the [GetMonitorRedGreenOrBlueGain](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-getmonitorredgreenorbluegain) and [SetMonitorRedGreenOrBlueGain](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-setmonitorredgreenorbluegain) functions. |
| **MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS** | The monitor supports the [RestoreMonitorFactoryColorDefaults](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-restoremonitorfactorycolordefaults) function. |
| **MC_CAPS_RESTORE_FACTORY_DEFAULTS** | The monitor supports the [RestoreMonitorFactoryDefaults](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-restoremonitorfactorydefaults) function. |
| **MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS** | If this flag is present, calling the [RestoreMonitorFactoryDefaults](https://learn.microsoft.com/windows/desktop/api/highlevelmonitorconfigurationapi/nf-highlevelmonitorconfigurationapi-restoremonitorfactorydefaults) function enables all of the monitor settings used by the high-level monitor configuration functions. For more information, see the Remarks section in **RestoreMonitorFactoryDefaults**. |

The color temperature flags returned in *pdwSupportedColorTemperatures* specify which color temperatures are supported by the monitor. The following color temperature flags are defined.

| Value | Description |
| --- | --- |
| **MC_SUPPORTED_COLOR_TEMPERATURE_NONE** | No color temperatures are supported. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_4000K** | The monitor supports 4,000 kelvins (K) color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_5000K** | The monitor supports 5,000 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_6500K** | The monitor supports 6,500 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_7500K** | The monitor supports 7,500 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_8200K** | The monitor supports 8,200 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_9300K** | The monitor supports 9,300 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_10000K** | The monitor supports 10,000 K color temperature. |
| **MC_SUPPORTED_COLOR_TEMPERATURE_11500K** | The monitor supports 11,500 K color temperature. |

## See also

[Monitor Configuration Functions](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-functions)