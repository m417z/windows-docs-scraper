# HS\_HOST\_FREE\_MEMORY function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_FREE\_MEMORY** function frees any memory that was allocated earlier by a call to [**HS\_HOST\_ALLOCATE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-allocate-memory).

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*pvBuffer* \[in, optional\]
Pointer to the memory buffer.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_HOST\_ALLOCATE\_MEMORY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-allocate-memory)

