# HS\_HOST\_ALLOCATE\_MEMORY function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_ALLOCATE\_MEMORY** function returns an amount of memory specified by the caller.

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*dwByteCount* \[in\]
The amount of memory to allocate.

*ppvBuffer* \[out\]
Pointer to the buffer that contains the allocated memory.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

