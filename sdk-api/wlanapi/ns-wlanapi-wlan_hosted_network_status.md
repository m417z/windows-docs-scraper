# WLAN_HOSTED_NETWORK_STATUS structure

## Description

The **WLAN_HOSTED_NETWORK_STATUS** structure contains information about the status of the wireless Hosted Network.

## Members

### `HostedNetworkState`

The current state of the wireless Hosted Network.

If the value of this member is **wlan_hosted_network_unavailable**, then the values of the other fields in this structure should not be used.

### `IPDeviceID`

The actual network Device ID used for the wireless Hosted Network.

This is member is the GUID of a virtual wireless device which would not be available through calls to the [WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces) function. This GUID can be used for calling other higher layer networking functions that use the device GUID (IP Helper functions, for example).

### `wlanHostedNetworkBSSID`

The BSSID used by the wireless Hosted Network in packets, beacons, and probe responses.

### `dot11PhyType`

The physical type of the network interface used by wireless Hosted Network.

This is one of the types reported by the related physical interface. This value is correct only if the **HostedNetworkState** member is **wlan_hosted_network_active**.

### `ulChannelFrequency`

The channel frequency of the network interface used by wireless Hosted Network.

 This value is correct only if **HostedNetworkState** is **wlan_hosted_network_active**.

### `dwNumberOfPeers`

The current number of authenticated peers on the wireless Hosted Network.

 This value is correct only if **HostedNetworkState** is **wlan_hosted_network_active**.

### `PeerList.unique`

### `PeerList.size_is`

### `PeerList.size_is.dwNumberOfPeers`

### `PeerList`

An array of [WLAN_HOSTED_NETWORK_PEER_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_peer_state) structures describing each of the current peers on the wireless Hosted Network. The number of elements in the array is given by **dwNumberOfPeers** member.

 This value is correct only if **HostedNetworkState** is **wlan_hosted_network_active**.

## Remarks

The **WLAN_HOSTED_NETWORK_STATUS** structure is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and later.

The **WLAN_HOSTED_NETWORK_STATUS** structure is returned in a pointer in the *ppWlanHostedNetworkStatus* parameter by the [WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus) function.

## See also

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-mac-address-type)

[DOT11_PHY_TYPE](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-phy-type)

[WLAN_HOSTED_NETWORK_PEER_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_peer_state)

[WLAN_HOSTED_NETWORK_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_state)

[WlanEnumInterfaces](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanenuminterfaces)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)