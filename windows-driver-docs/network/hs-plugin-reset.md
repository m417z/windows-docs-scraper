# HS\_PLUGIN\_RESET function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_RESET** function is called by the host to notify the plugin that it must reset its state.

## Parameters

This function has no parameters.

**

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

The plugin should terminate all threads and stop any activities in progress.

The plugin is unloaded if it fails to reset.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

