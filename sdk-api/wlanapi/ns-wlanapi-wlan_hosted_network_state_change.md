# WLAN_HOSTED_NETWORK_STATE_CHANGE structure

## Description

The **WLAN_HOSTED_NETWORK_STATE_CHANGE** structure contains information about a network state change on the wireless Hosted Network.

## Members

### `OldState`

The previous network state on the wireless Hosted Network.

### `NewState`

The current network state on the wireless Hosted Network.

### `StateChangeReason`

The reason for the network state change.

## Remarks

The **WLAN_HOSTED_NETWORK_STATE_CHANGE** structure is an extension to native wireless APIs added to support the wireless Hosted Network on Windows 7 and later.

## See also

[WLAN_HOSTED_NETWORK_REASON](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_reason)

[WLAN_HOSTED_NETWORK_STATE](https://learn.microsoft.com/windows/desktop/api/wlanapi/ne-wlanapi-wlan_hosted_network_state)

[WLAN_NOTIFICATION_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms706902(v=vs.85))

[WlanRegisterNotification](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanregisternotification)