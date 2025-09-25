# PeerCollabRefreshEndpointData function

## Description

The **PeerCollabRefreshEndpointData** function updates the calling peer node with new endpoint data.

## Parameters

### `pcEndpoint` [in]

Pointer to a [PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint) structure that contains the updated peer endpoint information for the current peer node.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **E_INVALIDARG** | One of the arguments is invalid. |

## Remarks

**PeerCollabRefreshEndpointData** allows an application to refresh data associated with the endpoint. Upon completion of the API, the PEER_EVENT_REQUEST_STATUS_CHANGED event will be raised. The event will contain a success or failure code.

On success, the application can call functions like [PeerCollabGetPresenceInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetpresenceinfo), [PeerCollabEnumApplications](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumapplications), [PeerCollabEnumObjects](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumobjects), and [PeerCollabQueryContactData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabquerycontactdata) to obtain additional data.
When the data is no longer needed it can be deleted by calling [PeerCollabDeleteEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabdeleteendpointdata).

If a peer is subscribed to the endpoint, the subscribed data takes higher precedence than the data that was cached by calling PeerCollabRefreshEndpointDataand will return **PEER_EVENT_REQUEST_STATUS_CHANGED**.

The **PeerCollabRefreshEndpointData** API takes a snapshot of the data for the specified endpoint. If endpoint data changes after this snapshot is taken, the caller will have a stale copy of the data. If PeerCollabRefreshEndpointData is called by an application multiple times for the same endpoint, the latest data received replaces the data stored from an earlier call to the API. However, in order to ensure that the caller is notified of any changes and always has the latest copy, [PeerCollabSubscribeEndpointData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabsubscribeendpointdata) is recommended instead of **PeerCollabRefreshEndpointData**.

The **PeerCollabRefreshEndpointData** function will timeout at 30 seconds.

## See also

[PEER_ENDPOINT](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_endpoint)

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabEnumApplications](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumapplications)

[PeerCollabEnumObjects](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabenumobjects)

[PeerCollabGetPresenceInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabgetpresenceinfo)