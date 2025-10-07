# HS\_HOST\_SEND\_USER\_MESSAGE function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_SEND\_USER\_MESSAGE** function is called to communicate with the user. The message content is contained in custom UI display strings that are passed to the hotspot offload service.

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*dwConnectionId* \[in\]
Unique identifier for the network connection.

*dwStringID* \[in\]
The string ID, used as an index into the string table where the message is stored.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Remarks

The hotspot plugin stores the messages in a string table. The plugin must pass the string IDs to the hotspot offload service to enable it to load the appropriate strings.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

