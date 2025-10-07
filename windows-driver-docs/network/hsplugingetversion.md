# HSPluginGetVersion function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HSPluginGetVersion** function is exported by the plugin DLL and is called to verify that the plugin version matches the host version.

## Parameters

*\*pHotspotPluginVersion* \[out\]
A pointer to the [**HS\_PLUGIN\_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-version) structure that contains version information for the plugin.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_VERSION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-version)

