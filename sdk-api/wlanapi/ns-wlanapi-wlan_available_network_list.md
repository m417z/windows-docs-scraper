# WLAN_AVAILABLE_NETWORK_LIST structure

## Description

The **WLAN_AVAILABLE_NETWORK_LIST** structure contains an array of information about available networks.

## Members

### `dwNumberOfItems`

Contains the number of items in the **Network** member.

### `dwIndex`

The index of the current item. The index of the first item is 0. **dwIndex** must be less than **dwNumberOfItems**.

This member is not used by the wireless service. Applications can use this member when processing individual networks in the **WLAN_AVAILABLE_NETWORK_LIST** structure. When an application passes this structure from one function to another, it can set the value of **dwIndex** to the index of the item currently being processed. This can help an application maintain state.

**dwIndex** should always be initialized before use.

### `Network.unique`

### `Network.size_is`

### `Network.size_is.dwNumberOfItems`

### `Network`

An array of [WLAN_AVAILABLE_NETWORK](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_available_network) structures containing interface information.

## See also

[WlanGetAvailableNetworkList](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlangetavailablenetworklist)