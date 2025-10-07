# HS\_PLUGIN\_SUPPORTED\_SIMS structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_SUPPORTED\_SIMS** structure contains the list of supported SIM configurations. This list must be supplied if the hotspot plugin requires HTTP or EAP authentication for any of its networks.

## Members

**dwCount**
The list size.

**pSupportedSIMs**
Used if MIDL is utilized. Unique, size is (dwCount).

An array of HS\_SIM\_IDENTITY structures that make up the list of supported SIM configurations.

**pSupportedSIMs**
Used if MIDL is not utilized.

An array of HS\_SIM\_IDENTITY structures that make up the list of supported SIM configurations.

## Remarks

In the **dwEapMethods** field of the [**HS\_SIM\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-identity) structure for each SIM configuration, you must specify the EAP methods that it supports.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_SIM\_IDENTITY**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-sim-identity)

[Microsoft Interface Definition Language](https://learn.microsoft.com/windows/desktop/Midl/midl-start-page)

