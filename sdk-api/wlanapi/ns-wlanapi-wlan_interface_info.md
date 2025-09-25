# WLAN_INTERFACE_INFO structure

## Description

The **WLAN_INTERFACE_INFO** structure contains information about a wireless LAN interface.

## Members

### `InterfaceGuid`

Contains the GUID of the interface.

### `strInterfaceDescription`

Contains the description of the interface.

### `isState`

Contains a [WLAN_INTERFACE_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_interface_state-r1) value that indicates the current state of the interface.

**Windows XP with SP3 and Wireless LAN API for Windows XP with SP2:** Only the **wlan_interface_state_connected**, **wlan_interface_state_disconnected**, and **wlan_interface_state_authenticating** values are supported.

## See also

[WLAN_INTERFACE_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info_list)