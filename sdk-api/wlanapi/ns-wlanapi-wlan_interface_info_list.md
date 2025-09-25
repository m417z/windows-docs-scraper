# WLAN_INTERFACE_INFO_LIST structure

## Description

The **WLAN_INTERFACE_INFO_LIST** structure contains an array of NIC interface information.

## Members

### `dwNumberOfItems`

Contains the number of items in the **InterfaceInfo** member.

### `dwIndex`

The index of the current item. The index of the first item is 0. **dwIndex** must be less than **dwNumberOfItems**.

This member is not used by the wireless service. Applications can use this member when processing individual interfaces in the **WLAN_INTERFACE_INFO_LIST** structure. When an application passes this structure from one function to another, it can set the value of **dwIndex** to the index of the item currently being processed. This can help an application maintain state.

**dwIndex** should always be initialized before use.

### `InterfaceInfo.unique`

### `InterfaceInfo.size_is`

### `InterfaceInfo.size_is.dwNumberOfItems`

### `InterfaceInfo`

An array of [WLAN_INTERFACE_INFO](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_interface_info) structures containing interface information.

## See also

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)