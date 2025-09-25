# DOT11_NETWORK_LIST structure

## Description

The **DOT11_NETWORK_LIST** structure contains a list of 802.11 wireless networks.

## Members

### `dwNumberOfItems`

Contains the number of items in the **Network** member.

### `dwIndex`

The index of the current item. The index of the first item is 0. **dwIndex** must be less than **dwNumberOfItems**.

This member is not used by the wireless service. Applications can use this member when processing individual networks in the **DOT11_NETWORK_LIST** structure. When an application passes this structure from one function to another, it can set the value of **dwIndex** to the index of the item currently being processed. This can help an application maintain state.

**dwIndex** should always be initialized before use.

### `Network.unique`

### `Network.size_is`

### `Network.size_is.dwNumberOfItems`

### `Network`

An array of [DOT11_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network) structures that contain 802.11 wireless network information.

## See also

[DOT11_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-dot11_network)

[WlanGetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetfilterlist)

[WlanSetFilterList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlansetfilterlist)