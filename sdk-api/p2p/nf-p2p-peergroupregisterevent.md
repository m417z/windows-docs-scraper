# PeerGroupRegisterEvent function

## Description

The **PeerGroupRegisterEvent** function registers a peer for specific peer group events.

## Parameters

### `hGroup` [in]

Handle of the peer group on which to monitor the specific peer events. This handle is returned by the [PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate), [PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen), or [PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin) function. This parameter is required.

### `hEvent` [in]

Pointer to a Windows event handle, which is signaled when a peer event is fired. When this handle is signaled, the peer should call [PeerGroupGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgeteventdata) until the function returns **PEER_S_NO_EVENT_DATA**. This parameter is required.

### `cEventRegistration` [in]

Contains the number of [PEER_GROUP_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_event_registration) structures listed in *pEventRegistrations*. This parameter is required.

### `pEventRegistrations` [in]

Pointer to a list of [PEER_GROUP_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_event_registration)
structures that contains the peer event types for which registration occurs. This parameter is required.

### `phPeerEvent` [out]

Pointer to the returned HPEEREVENT handle. A peer can unregister for this peer event by passing this handle to [PeerGroupUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupunregisterevent). This parameter is required.

## Return value

Returns **S_OK** if the operation succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_INVALID_GROUP** | The handle to the group is invalid. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

Before you close the HPEEREVENT handle, you must unregister for the peer event types by passing the handle to [PeerGroupUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupunregisterevent).

## See also

[PEER_GROUP_EVENT_DATA](https://learn.microsoft.com/windows/win32/api/p2p/ns-p2p-peer_group_event_data-r1)

[PEER_GROUP_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_group_event_registration)

[PeerGroupCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupcreate)

[PeerGroupGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupgeteventdata)

[PeerGroupJoin](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupjoin)

[PeerGroupOpen](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupopen)

[PeerGroupUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupunregisterevent)