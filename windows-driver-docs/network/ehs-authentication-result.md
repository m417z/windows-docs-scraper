# eHS\_AUTHENTICATION\_RESULT enumeration

[!include[Wi-Fi Hotspot Offloading deprecation](https://learn.microsoft.com/windows-hardware/drivers/includes/wi-fi-hotspot-offloading-deprecation)]

The **eHS\_AUTHENTICATION\_RESULT** enumeration indicates the result of authentication by the plugin after the PostConnectAuth request.

## Constants

**HS\_AUTHENTICATION\_RESULT\_SUCCESS**
Indicates the authentication was successful.

**HS\_AUTHENTICATION\_RESULT\_FAILED\_TIMEOUT**
Indicates the authentication failed due to a timeout from the server/back end.

**HS\_AUTHENTICATION\_RESULT\_FAILED\_AUTH**
Indicates the authentication failed due to incorrect credentials.

**HS\_AUTHENTICATION\_RESULT\_FAILED\_CONNECT**
Indicates the authentication failed due to an inability to connect to the authentication server

**HS\_AUTHENTICATION\_RESULT\_FAILED\_OTHER**
Indicates the authentication failed for some other reason.

**HS\_AUTHENTICATION\_RESULT\_MAX**
Indicates an out-of-range value.

## Remarks

The plugin passes this enumeration value to the hotspot plugin host through the [**HS\_HOST\_POST\_CONNECT\_AUTH\_COMPLETION**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-host-post-connect-auth-completion) function, which is used to inform the hotspot plugin host of the results of a call to [**HS\_PLUGIN\_START\_POST\_CONNECT\_AUTH**](https://learn.microsoft.com/windows-hardware/drivers/network/hs-plugin-start-post-connect-auth).

## Requirements

|  |  |
| --- | --- |
| Version | Windows 10 Mobile |
| Header | Hotspotoffloadplugin.h (include Hotspotoffloadplugin.h) |

