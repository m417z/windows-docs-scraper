# HS\_PLUGIN\_IS\_HOTSPOT\_NETWORK function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_IS\_HOTSPOT\_NETWORK** function is called by the host to determine if a specified network is a hotspot network.

## Parameters

*\*pNetworkIdentity* \[in\]
Pointer to the [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure for the network from which the device is to be disconnected.

*\*pNetworkState* \[out\]
An [**eHS\_NETWORK\_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-network-state) enumeration value that indicates the type of network.

*\*pNetworkProfile* \[out, optional\]
Pointer to the [**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile) structure for the network.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

[**eHS\_NETWORK\_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-network-state)

[**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile)

