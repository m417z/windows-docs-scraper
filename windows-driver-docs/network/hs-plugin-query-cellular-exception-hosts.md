# HS\_PLUGIN\_QUERY\_CELLULAR\_EXCEPTION\_HOSTS function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_PLUGIN\_QUERY\_CELLULAR\_EXCEPTION\_HOSTS** function queries the list of hosts that the plugin will need to connect to over cellular as part of its authentication process.

## Parameters

*\*pExceptionsList* \[in, out\]
The [**HS\_PLUGIN\_CELLULAR\_EXCEPTION\_HOSTS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-cellular-exception-hosts) structure that contains the list of cellular host names.

## Return value

This function is called by the host to communicate with the plugin and does not return a value.

## Remarks

This function is called only if the plugin sets the **dwNumCellularExceptions** field of its [**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile) to a value greater than zero.

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**HS\_PLUGIN\_CELLULAR\_EXCEPTION\_HOSTS**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-cellular-exception-hosts)

[**HS\_PLUGIN\_PROFILE**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-profile)

