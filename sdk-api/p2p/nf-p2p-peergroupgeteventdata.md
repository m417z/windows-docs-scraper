# PeerGroupGetEventData function

## Description

The **PeerGroupGetEventData** function allows an application to retrieve the data returned by a grouping event.

## Parameters

### `hPeerEvent` [in]

Handle obtained from a previous call to [PeerGroupRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupregisterevent). This parameter is required.

### `ppEventData` [out]

Pointer to a [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) structure that contains data about the peer event. This data structure must be freed after use with [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_S_NO_EVENT_DATA** | The call is successful, but there is no event data available. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

When an event occurs for which a peer has requested notification, the corresponding peer event handle is signaled. The peer calls this method until [PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1) structures are retrieved. Each data structure contains the following two key pieces of data:

* The registration associated with a peer event.
* The actual data for a peer event.

## See also

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata)

[PeerGroupRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupregisterevent)