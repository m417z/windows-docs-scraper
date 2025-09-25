# WLAN_CONNECTION_ATTRIBUTES structure

## Description

The **WLAN_CONNECTION_ATTRIBUTES** structure defines the attributes of a wireless connection.

## Members

### `isState`

A [WLAN_INTERFACE_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_interface_state-r1) value that indicates the state of the interface.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_interface_state_connected**, **wlan_interface_state_disconnected**, and **wlan_interface_state_authenticating** values are supported.

### `wlanConnectionMode`

A [WLAN_CONNECTION_MODE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_connection_mode) value that indicates the mode of the connection.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_connection_mode_profile** value is supported.

### `strProfileName`

The name of the profile used for the connection. Profile names are case-sensitive. This string must be NULL-terminated.

### `wlanAssociationAttributes`

A [WLAN_ASSOCIATION_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_association_attributes) structure that contains the attributes of the association.

### `wlanSecurityAttributes`

A [WLAN_SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_security_attributes) structure that contains the security attributes of the connection.

## See also

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)