# HS\_PLUGIN\_PRE\_CONNECT\_INIT function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_PRE\_CONNECT\_INIT** function is called to notify the plugin to initialize its state when a connection to a hotspot network is in progress.

## Parameters

*\*pNetworkIdentity* \[in\]
Pointer to the [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure for the target network.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

