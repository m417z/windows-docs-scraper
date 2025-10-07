# HS\_PLUGIN\_CHECK\_FOR\_UPDATES function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_CHECK\_FOR\_UPDATES** function checks for configuration updates at the frequency specified in the **dwProfileUpdateTimeDays** member of the plugin’s [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure.

## Parameters

This function has no parameters.

**

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

