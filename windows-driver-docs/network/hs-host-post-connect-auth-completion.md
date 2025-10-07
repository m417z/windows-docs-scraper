# HS\_HOST\_POST\_CONNECT\_AUTH\_COMPLETION function

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **HS\_HOST\_POST\_CONNECT\_AUTH\_COMPLETION** function indicates the success or failure of an authentication attempt following a Wi-Fi connection setup at layer 2.

## Parameters

*hPluginContext* \[in\]
Context handle for the plugin making the call to this function.

*dwConnectionId* \[in\]
Unique identifier for the network connection.

*AuthResult* \[in\]
The [**eHS\_AUTHENTICATION\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-authentication-result) enumeration value that indicates success or failure.

*pvReserved* \[in, optional\]
Reserved for future use.

## Return value

This function is called by the plugin to communicate with the host and does not return a value.

## Remarks

The plugin must call this function to inform the host of the result of a previous call to [**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth).

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

## See also

[**eHS\_AUTHENTICATION\_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/network/ehs-authentication-result)

[**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth)

