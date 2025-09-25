# WLAN_HOSTED_NETWORK_PEER_STATE structure

## Description

The **WLAN_HOSTED_NETWORK_PEER_STATE** structure contains information about the peer state for a peer on the wireless Hosted Network.

## Members

### `PeerMacAddress`

The MAC address of the peer being described.

### `PeerAuthState`

The current authentication state of this peer.

## Remarks

The **WLAN_HOSTED_NETWORK_PEER_STATE** structure is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and later.

## See also

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows/desktop/NativeWiFi/dot11-mac-address-type)

[WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE](https://learn.microsoft.com/windows/win32/api/wlanapi/ns-wlanapi-wlan_hosted_network_data_peer_state_change)

[WLAN_HOSTED_NETWORK_PEER_AUTH_STATE](https://learn.microsoft.com/windows/win32/api/wlanapi/ne-wlanapi-wlan_hosted_network_peer_auth_state)

[WLAN_HOSTED_NETWORK_STATUS](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_status)

[WlanHostedNetworkQueryStatus](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanhostednetworkquerystatus)