# WLAN_CONNECTION_MODE enumeration

## Description

The **WLAN_CONNECTION_MODE** enumerated type defines the mode of connection.**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_connection_mode_profile** value is supported.

## Constants

### `wlan_connection_mode_profile:0`

A profile will be used to make the connection.

### `wlan_connection_mode_temporary_profile`

A temporary profile will be used to make the connection.

### `wlan_connection_mode_discovery_secure`

Secure discovery will be used to make the connection.

### `wlan_connection_mode_discovery_unsecure`

Unsecure discovery will be used to make the connection.

### `wlan_connection_mode_auto`

The connection is initiated by the wireless service automatically using a persistent profile.

### `wlan_connection_mode_invalid`

Not used.

## See also

[WLAN_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_attributes)

[WLAN_CONNECTION_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_notification_data)

[WLAN_CONNECTION_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_parameters)