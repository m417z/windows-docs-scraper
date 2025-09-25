# WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE structure

## Description

The **WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE** structure contains information about a network state change for a data peer on the wireless Hosted Network.

## Members

### `OldState`

The previous network state for a data peer on the wireless Hosted Network.

### `NewState`

The current network state for a data peer on the wireless Hosted Network.

### `PeerStateChangeReason`

The reason for the network state change for the data peer.

## Remarks

The **WLAN_HOSTED_NETWORK_DATA_PEER_STATE_CHANGE** structure is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and later.

## See also

[WLAN_HOSTED_NETWORK_PEER_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ns-wlanapi-wlan_hosted_network_peer_state)

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)