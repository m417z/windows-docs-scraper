# PeerPnrpStartResolve function

## Description

The **PeerPnrpStartResolve** function starts an asynchronous peer name resolution operation.

## Parameters

### `pcwzPeerName` [in]

Pointer to a zero-terminated string that contains the peer name for which endpoint addresses will be obtained.

### `pcwzCloudName` [in, optional]

Pointer to a zero-terminated string that contains the name of the PNRP cloud under which to resolve the peer name. If **NULL**, resolution is performed for all clouds. If PEER_PNRP_ALL_LINK_CLOUDS, resolution is performed for all link local clouds. When "GLOBAL_" is specified, resolution takes place in the global cloud.

### `cMaxEndpoints` [in, optional]

The maximum number of endpoints to return for the peer name.

### `hEvent` [in]

Handle to the event signaled when a peer endpoint is resolved for the supplied peer name and are ready for consumption by calling PeerPnrpGetEndpoint. This event is signaled for every endpoint discovered by the PNRP service. If PEER_NO_MORE is returned by a call to [PeerPnrpGetEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpgetendpoint), then all endpoints have been found for that peer.

### `phResolve` [out]

Handle to this peer name resolution request. This handle must be provided to [PeerPnrpEndResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpendresolve) after the resolution events are raised and the endpoints are obtained with corresponding calls to [PeerPnrpGetEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpgetendpoint), or if the operation fails.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## Remarks

**PeerPnrpStartResolve** creates a handle to an asynchronous peer name resolution operation.

Whenever an endpoint is found, the event handle provided in *hEvent* is signaled, and [PeerPnrpGetEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpgetendpoint) must be called with the *phResolve* handle by the application to obtain that endpoint.

The last event specifies the PEER_E_NO_MORE error code, indicating that all endpoints corresponding to the peer name supplied to **PeerPnrpStartResolve** have been found. At this time, the application must close the handle with a call to [PeerPnrpEndResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpendresolve).

A handle must be resolved in a process separate from the process in which it was registered. If a handle is registered and resolved within the same process it will not be recognized.

## See also

[PeerPnrpEndResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpendresolve)

[PeerPnrpGetEndpoint](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpgetendpoint)

[PeerPnrpResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpresolve)