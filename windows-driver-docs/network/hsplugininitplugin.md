# HSPluginInitPlugin function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HSPluginInitPlugin** function is exported by the plugin DLL and is called to initialize the plugin.

## Parameters

*hPluginContext* \[in\]
A handle, provided by the host, that the plugin is required to save and then use when it needs to make a request to the host by way of the host handler functions.

*dwVerNumUsed* \[in\]
The host's current version number.

*dwHostCapabilities* \[in\]
Value that specifies the list of capabilities that the host can provide to the plugin. This value is the bitwise OR combination of the applicable capability flags. For more information about capability flags, see the **HS\_FLAG\_CAPABILITY\_\\*** constants in [**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants).

**Note** If the host does not supply all the capabilities required by the plugin, the plugin will not be initialized.

*\*pDeviceIdentity* \[in\]
Pointer to a [**HS\_DEVICE\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-device-identity) structure that contains information about the device manufacturer and model.

*\*pHotspotHostHandlers* \[in\]
Pointer to a [**HOTSPOT\_HOST\_HANDLERS**](https://learn.microsoft.com/windows-hardware/drivers/network/hotspot-host-handlers) structure that contains the hotspot host handlers function table. This table contains pointers to functions that are called by the plugin to communicate with the hotspot host.

*\*pHotspotPluginAPIs* \[out\]
Pointer to the [**HOTSPOT\_PLUGIN\_APIS**](https://learn.microsoft.com/windows-hardware/drivers/network/hotspot-plugin-apis) structure that contains the hotspot plugin APIs function table. This table is returned by the plugin and contains pointers to functions that are called by the host to communicate with the plugin.

*\*pPluginProfile* \[out\]
Pointer to a [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure, returned by the plugin, that provides information about the plugin.

## Remarks

During initialization, the host provides the following:

- The plugin context handle
- The current version number
- A list of capabilities that the host can provide to the plugin
- A pointer to the host handler function table through which the plugin can communicate with the host

The plugin returns a pointer to its own function table and a pointer to its [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants)

[**HS\_DEVICE\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-device-identity)

[**HOTSPOT\_HOST\_HANDLERS**](https://learn.microsoft.com/windows-hardware/drivers/network/hotspot-host-handlers)

[**HOTSPOT\_PLUGIN\_APIS**](https://learn.microsoft.com/windows-hardware/drivers/network/hotspot-plugin-apis)

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

