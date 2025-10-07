# HS\_CONNECTION\_CONTEXT structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_CONNECTION\_CONTEXT** structure contains the information required by the plugin for post connect authentication.

## Members

**MacAddress**
The [**HS\_MAC\_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-mac-address) structure that contains the MAC address.

**SIMIdentity**
The [**HS\_SIM\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-identity) structure that contains information required for EAP-SIM/AKA authentication.

**pszPhoneNumber**
Pointer to the phone number.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_MAC\_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-mac-address)

[**HS\_SIM\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-identity)

