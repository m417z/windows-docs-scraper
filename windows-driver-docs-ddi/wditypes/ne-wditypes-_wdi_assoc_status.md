# _WDI_ASSOC_STATUS enumeration

## Description

> [!IMPORTANT]
> This topic is part of the [WDI driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) released in Windows 10. The WDI driver model is in maintenance mode and will only receive high priority fixes. [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features.

The WDI_ASSOC_STATUS enumeration defines the association status values.

## Constants

### `WDI_ASSOC_STATUS_SUCCESS:0`

The operation completed successfully.

### `WDI_ASSOC_STATUS_FAILURE:1`

The operation completed with a failure and none of the other status codes apply.

### `WDI_ASSOC_STATUS_UNREACHABLE:2`

The operation failed because the peer is unreachable. The detection of an unreachable peer is up to the port. For example, a peer can be considered unreachable if the port does not receive responses to management requests such as probe requests or association requests. If the device has more specific information, it should use one of the more specific reason codes.

### `WDI_ASSOC_STATUS_RADIO_OFF:3`

The operation failed because the radio is off. This can be used if the hardware radio switch is turned off.

### `WDI_ASSOC_STATUS_PHY_DISABLED:4`
The operation failed because the PHY is disabled.

### `WDI_ASSOC_STATUS_ABORTED:5`

The operation was cancelled due to a request from the host. If the request from the host was for disassociation, WDI_ASSOC_STATUS_DISASSOCIATED_BY_HOST should be used.

### `WDI_ASSOC_STATUS_CANDIDATE_LIST_EXHAUSTED:6`

The connect or roaming operation failed because the post could not successfully associate.

### `WDI_ASSOC_STATUS_PROBE_TX_FAILURE:30`

The association failed because the port was not able to successfully send a 802.11 probe request to the peer.

### `WDI_ASSOC_STATUS_NO_BEACON_PROBE_RESPONSE:31`

The association failed because no beacon or probe response was received from the peer.

### `WDI_ASSOC_STATUS_AUTH_REQUEST_NO_ACK:40`
The association failed because the port was unable to get an ACK for the 802.11 authentication request frame.

### `WDI_ASSOC_STATUS_NO_AUTH_RESPONSE:41`

The association failed because an 802.11 authentication response frame was not received after a successful send of an 802.11 authentication request.

### `WDI_ASSOC_STATUS_AUTH_RESPONSE_CAPABILITY_MISMATCH:42`

The association failed because an 802.11 authentication response was received with a status of success, but was rejected due to capability mismatch.

### `WDI_ASSOC_STATUS_BAD_AUTH_RESPONSE:43`

The association failed because an 802.11 authentication response was received with a status of success, but was rejected due to a reason other than capability mismatch (for example, because of invalid content).

### `WDI_ASSOC_STATUS_AUTH_FAILED_BY_PEER:44`

The association failed because the peer failed the 802.11 authentication with a failure reason. The authentication response frame must be included in the indication.

### `WDI_ASSOC_STATUS_AUTH_EXCHANGE_FAILURE:45`

The association failed because the 802.11 authentication did not finish successfully. This reason should only be used if the port is not able to use one of the specific 802.11 authentication exchange failure codes.

### `WDI_ASSOC_STATUS_ASSOC_REQUEST_NO_ACK:50`
The association failed because port was unable to get an ACK for the 802.11 association request frame.

### `WDI_ASSOC_STATUS_NO_ASSOC_RESPONSE:51`

The association failed because an 802.11 association response frame was not received after a successful send of an 802.11 association request.

### `WDI_ASSOC_STATUS_ASSOC_RESPONSE_CAPABILITY_MISMATCH:52`

The association failed because an 802.11 association response was received with a status of success, but was rejected due to capability mismatch. The association response frame should be included in the indication.

### `WDI_ASSOC_STATUS_BAD_ASSOC_RESPONSE:53`

The association failed because an 802.11 association response was received with a status of success, but was rejected due to a reason other than capability mismatch (for example, because of invalid content). The association response frame should be included in the indication.

### `WDI_ASSOC_STATUS_ASSOC_FAILED_BY_PEER:54`

The association failed because the peer failed the 802.11 association request with a failure reason. The association response frame should be included in the indication.

### `WDI_ASSOC_STATUS_ASSOC_EXCHANGE_FAILURE:55`

The association failed because the 802.11 association did not finish successfully. This reason should only be used if the port is not able to use one of the specific 802.11 association exchange failure codes.

### `WDI_ASSOC_STATUS_DISASSOCIATED_BY_HOST:7`

The host requested that the port disassociate.

### `WDI_ASSOC_STATUS_DISASSOCIATE_BY_DEVICE_RESET:60`

The disassociation is because the device was reset (for example, due to a hang, NdisReset, or a reset that the miniport did internally).

### `WDI_ASSOC_STATUS_DISASSOCIATE_UNABLE_TO_MAINTAIN:61`

The disassociation is because the port is unable to maintain the connection due to other operations being performed on the port (for example, Bluetooth coexistence reasons). This should only be used if the port is not able to use one of the specific failure codes.

### `WDI_ASSOC_STATUS_DISASSOCIATE_NOT_VISIBLE:62`

The operation failed because the peer is not being heard from. The detection of an unreachable peer is up to the port. For example, a peer can be considered unreachable if the port misses multiple beacons from the peer.

### `WDI_ASSOC_STATUS_DISASSOCIATE_NEEDED_REASSOC:63`

The disassociation is because the port believes it needs to reassociate to the peer. This may be because the port determines that the peer thinks the association is no longer valid. This should only be used if the port is not able to use one of the specific failure codes (for example, WDI_ASSOC_STATUS_PEER_DEAUTHENTICATED).

### `WDI_ASSOC_STATUS_PEER_DEAUTHENTICATED:13`

The port received a deauthentication frame from the peer. The deauthentication frame must be included in the indication.

### `WDI_ASSOC_STATUS_PEER_DISASSOCIATED:14`

The port received a disassociation frame from the peer. The disassociation frame must be included in the indication.

### `WDI_ASSOC_STATUS_ROAMING_BETTER_AP_FOUND:10`

The connection was torn down because a better access point was found.

### `WDI_ASSOC_STATUS_ROAMING_ASSOCIATION_LOST:11`

The port lost the link with the peer. If device has more specific information, it should use one of the more specific reason codes such as WDI_ASSOC_STATUS_DISASSOCIATE_NOT_VISIBLE.

### `WDI_ASSOC_STATUS_ROAMING_LOW_LINK_QUALITY:15`

The link quality to the peer is low.

### `WDI_ASSOC_STATUS_RESERVED_0`
Reserved.

### `WDI_ASSOC_STATUS_RESERVED_1`
Reserved.

### `WDI_ASSOC_STATUS_RESERVED_2`

Reserved.