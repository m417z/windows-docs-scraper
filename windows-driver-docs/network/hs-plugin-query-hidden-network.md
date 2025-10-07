# HS\_PLUGIN\_QUERY\_HIDDEN\_NETWORK function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_QUERY\_HIDDEN\_NETWORK** function returns the network identity and network profile for a hidden network.

## Parameters

*\*pHiddenNetworkIdentity* \[out\]
The [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure that uniquely identifies the network.

*\*pHiddenNetworkProfile* \[out\]
The [**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile) structure that contains the network profile.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

The host calls this function only if the **dwPluginCapabilities** field of the associated plugin's [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) structure includes the **HS\_FLAG\_CAPABILITY\_NETWORK\_TYPE\_HIDDEN** capability.

The plugin must provide both the network identity and the network profile for the hidden Wi-Fi network.

This network must have the highest priority (1) among all the hotspot networks.

The hotspot offload service imposes a limitation of one hidden network for the life of the service. Therefore, in the case where there are multiple plugins installed, only the first plugin's request to specify a hidden network will be accepted.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

[**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile)

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

