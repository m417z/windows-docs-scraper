# HS\_PLUGIN\_PROFILE structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_PROFILE** structure provides information about the plugin. The members of this structure are set by the plugin during execution of the [**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin) function that is called by the host.

## Members

**dwPluginCapabilities**
Required.

A subset of the possible **HS\_FLAG\_CAPABILITY\_NETWORK\_\\*** values. For more information about hotspot host capabilities, see [**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants).

**dwNumNetworksSupported**
Required.

Total number of networks supported by this plugin.

**dwProviderNameStringID**
Required.

The network provider name which is displayed to the user. Maximum string size = MAX\_PROVIDER\_NAME\_LENGTH.

**dwGenericNetworkNameStringID**
Optional.

Network name. Maximum string size = MAX\_NETWORK\_DISPLAY\_NAME\_LENGTH.

**dwAdvancedPageStringID**
Optional.

Maximum string size = HS\_CONST\_MAX\_ADVANCED\_PAGE\_STRING\_LENGTH.

**dwProfileUpdateTimeDays**
Optional.

Must be greater than or equal to HS\_CONST\_MIN\_PROFILE\_UPDATE\_TIME\_IN\_DAYS.

**szRealm**
Required if HS\_FLAG\_CAPABILITIES\_NETWORK\_CUSTOM\_REALM is set.

Network-specific realm value.

**dwSupportedSIMCount**
The size of the list pointed to by **pSupported SIMs**.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HSPluginInitPlugin**](https://learn.microsoft.com/windows-hardware/drivers/network/hsplugininitplugin)

[**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants)

