# HS\_HOST\_UPDATE\_CONFIGURATION\_COMPLETION function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_UPDATE\_CONFIGURATION\_COMPLETION** function indicates the success or failure of a request to check for updates.

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*UpdateResult* \[in\]
The [**eHS\_UPDATE\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-update-result) enumeration value that indicates the result of the request to check for updates.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Remarks

The plugin must call this function to inform the host of the result of a previous call to [**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates).

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**eHS\_UPDATE\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-update-result)

[**HS\_PLUGIN\_CHECK\_FOR\_UPDATES**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-check-for-updates)

