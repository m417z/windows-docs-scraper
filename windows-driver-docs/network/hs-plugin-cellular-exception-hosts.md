# HS\_PLUGIN\_CELLULAR\_EXCEPTION\_HOSTS structure

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_CELLULAR\_EXCEPTION\_HOSTS** structure contains the list of hosts that the plugin requires to be connected over a cellular bearer only during the authentication process. This is an optional capability that can be requested by the plugin. For more information, see [**HS\_PLUGIN\_QUERY\_CELLULAR\_EXCEPTION\_HOSTS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-cellular-exception-hosts).

## Members

**dwCount**
The number of host names in the list pointed to by **pExceptions**.

**pExceptions**
Used if MIDL is utilized. Unique, size is (dwCount).

Pointer to the list of host names.

**pExceptions**
Used if MIDL is not utilized.

Pointer to the list of host names.

## Requirements

|  |  |
| --- | --- |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_QUERY\_CELLULAR\_EXCEPTION\_HOSTS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-query-cellular-exception-hosts)

[Microsoft Interface Definition Language](https://learn.microsoft.com/windows/desktop/Midl/midl-start-page)

