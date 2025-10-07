# HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH** function is called to perform any post-connect authentication required to authenticate the device over the network.

## Parameters

*dwConnectionId* \[in\]
Unique identifier for the network connection.

*\*pConnectContext* \[in\]
Pointer to a [**HS\_CONNECTION\_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-connection-context) structure that contains the information required by the plugin for post-connect authentication.

*\*pSIMData* \[in\]
Pointer to a [**HS\_SIM\_DATA**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-data) structure that contains information from the SIM required by the plugin for post-connect authentication.

*\*pNetworkIdentity* \[in\]
Pointer to the [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure for the network.

*\*pNetworkProfile* \[in\]
Pointer to the [**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile) structure that contains the network profile.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

After calling this function, the plugin must call the [**HS\_HOST\_POST\_CONNECT\_AUTH\_COMPLETION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-post-connect-auth-completion) handler to inform the host of the status of the request.

If the network uses EAP-SIM/AKA authentication, the plugin is not expected to perform any activity in this state. However, if the network requires HTTP-based authentication, the plugin must perform the appropriate authentication.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_CONNECTION\_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-connection-context)

[**HS\_SIM\_DATA**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-data)

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

[**HS\_NETWORK\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-profile)

