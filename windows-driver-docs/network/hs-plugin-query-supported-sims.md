# HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_QUERY\_SUPPORTED\_SIMS** function returns the list of SIMs that the plugin supports.

## Parameters

*\*pNetworkIdentity* \[in, optional\]
The [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure that uniquely identifies the network.

*\*pSupportedSIMs* \[in, out\]
Pointer to an array of one or more [**HS\_PLUGIN\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-supported-sims) structures that contains the list of supported SIMs.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

If the *pNetworkIdentity* parameter exists then only those SIM identities required for connecting to the specified network must be provided, otherwise the entire list of SIMs for connecting to all networks must be provided.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

[**HS\_PLUGIN\_SUPPORTED\_SIMS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-supported-sims)

