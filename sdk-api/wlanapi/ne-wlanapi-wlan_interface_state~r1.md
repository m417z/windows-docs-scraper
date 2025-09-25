# WLAN_INTERFACE_STATE enumeration

## Description

The **WLAN_INTERFACE_STATE** enumerated type indicates the state of an interface.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_interface_state_connected**, **wlan_interface_state_disconnected**, and **wlan_interface_state_authenticating** values are supported.

## Constants

### `wlan_interface_state_not_ready`

The interface is not ready to operate.

### `wlan_interface_state_connected`

The interface is connected to a network.

### `wlan_interface_state_ad_hoc_network_formed`

The interface is the first node in an ad hoc network. No peer has connected.

### `wlan_interface_state_disconnecting`

The interface is disconnecting from the current network.

### `wlan_interface_state_disconnected`

The interface is not connected to any network.

### `wlan_interface_state_associating`

The interface is attempting to associate with a network.

### `wlan_interface_state_discovering`

Auto configuration is discovering the settings for the network.

### `wlan_interface_state_authenticating`

The interface is in the process of authenticating.

## Remarks

## See also

[WLAN_CONNECTION_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_connection_attributes)

[WLAN_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info)

[WlanQueryInterface](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanqueryinterface)