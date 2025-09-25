# PeerPnrpGetEndpoint function

## Description

The **PeerPnrpGetEndpoint** function retrieves a peer endpoint address resolved during an asynchronous peer name resolution operation.

## Parameters

### `hResolve` [in]

The handle to the asynchronous peer name resolution operation returned by a previous call to [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve).

### `ppEndpoint` [out]

Pointer to the address of a [PEER_PNRP_ENDPOINT_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_pnrp_endpoint_info) structure that contains an endpoint address for the peer name supplied in the previous call to [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve).

This data returned by this parameter must be freed by calling [PeerFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_NO_MORE** | All endpoint addresses have been retrieved for the peer. |

## Remarks

[PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve) creates a handle to an asynchronous peer name resolution operation.

Whenever an endpoint is found, the event handle provided in *hEvent* is signaled, and **PeerPnrpGetEndpoint** must be called with the *phResolve* handle by the application to obtain that endpoint.

The last event specifies the PEER_E_NO_MORE error code, indicating that all endpoints corresponding to the peer name supplied to [PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve) have been found. At this time, the application must close the handle with a call to [PeerPnrpEndResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpendresolve).

## See also

[PeerPnrpEndResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpendresolve)

[PeerPnrpStartResolve](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartresolve)