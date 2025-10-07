# HS\_PLUGIN\_DEINIT function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_DEINIT** function is called by the host to notify the plugin that it will be unloaded.

## Parameters

*UnloadReason* \[in\]
An [**eHS\_UNLOAD\_REASON**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-unload-reason) enumeration value that indicates the reason for the unload.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

Upon receiving notification that it will be unloaded, the plugin should complete any current activity and save state, if required.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**eHS\_UNLOAD\_REASON**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-unload-reason)

