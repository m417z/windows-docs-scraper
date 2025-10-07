# HS\_PLUGIN\_DISCONNECT\_FROM\_NETWORK function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_DISCONNECT\_FROM\_NETWORK** function notifies the plugin that the device will be disconnected from the network.

## Parameters

*\*pNetworkIdentity* \[in\]
Pointer to the [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure for the network from which the device is to be disconnected.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

