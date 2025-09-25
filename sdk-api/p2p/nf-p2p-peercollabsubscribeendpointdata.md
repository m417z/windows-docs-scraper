# PeerCollabSubscribeEndpointData function

## Description

The **PeerCollabSubscribeEndpointData** function creates a subscription to an available endpoint.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the peer endpoint used to obtain presence information.

## Return value

Returns S_OK or PEER_S_SUBSCRIPTION_EXISTS if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |

## Remarks

**PeerCollabSubscribeEndpointData** is an asynchronous call, meaning that the process to subscribe the endpoint has been started but not necessarily completed when this call returns. An application should wait for PEER_EVENT_REQUEST_STATUS_CHANGED to get the result of the subscription request.

This function will timeout at 30 seconds.

**PeerCollabSubscribeEndpointData** can be called multiple times from different applications for the same endpoint. Each call is reference counted; only when the last reference is released is a peer unsubscribed. To release the reference call **PeerCollabUnsubscribeEndpointData**.

When an application exits without calling [PeerCollabUnsubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunsubscribeendpointdata), all of the references for that application are released automatically.

To successfully call the [PeerCollabGetPresenceInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetpresenceinfo), [PeerCollabEnumApplications](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumapplications), [PeerCollabEnumObjects](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumobjects), and [PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata) APIs, an application must first call **PeerCollabSubscribeEndpointData**.

## See also

[PeerCollabEnumApplications](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumapplications)

[PeerCollabEnumObjects](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumobjects)

[PeerCollabGetPresenceInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetpresenceinfo)

[PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata)

[PeerCollabUnsubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabunsubscribeendpointdata)