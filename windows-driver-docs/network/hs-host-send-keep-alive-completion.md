# HS\_HOST\_SEND\_KEEP\_ALIVE\_COMPLETION function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_SEND\_KEEP\_ALIVE\_COMPLETION** function indicates the success or failure of a request for a network send keep-alive message.

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*dwResult* \[in\]
The result code.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Remarks

The plugin must call this function to inform the host of the result of a previous call to [**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive).

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_SEND\_KEEP\_ALIVE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-send-keep-alive)

