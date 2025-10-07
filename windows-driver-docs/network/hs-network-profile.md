# HS\_NETWORK\_PROFILE structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_NETWORK\_PROFILE** structure is provided by the plugin and contains information required for connection to the target network. Each instance of the Network Profile is uniquely associated with a corresponding [**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity) structure.

## Members

**dwNetworkCapabilities**
A subset of the possible **HS\_FLAG\_CAPABILITY\_NETWORK\_\\*** values. For more information about hotspot host capabilities, see [**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants).

**usPriority**
A unique priority value assigned to the associated network. It must be a value between 1 and 65000 (a hidden network must have a value of 1). A lower numeric value corresponds to a higher priority.

**dwSupportedSIMCount**
Supported SIM count. This member is set for HTTP-based and EAP-SIM/AKA/AKA' authentication.

**dmNumCellularExceptions**
Optional. Number of host connections over cellular only.

**dwNetworkStringID**
Network name string ID. Maximum string size = MAX\_NETWORK\_DISPLAY\_NAME\_LENGTH.

**dwKeepAliveTimeMins**
Optional. The time interval between network connection keep-alive messages.

**szRealm**
Network-specific realm value.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_NETWORK\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-network-identity)

[**Wi-Fi Hotspot Offloading Constants**](https://learn.microsoft.com/windows-hardware/drivers/network/wi-fi-hotspot-offloading-constants)

