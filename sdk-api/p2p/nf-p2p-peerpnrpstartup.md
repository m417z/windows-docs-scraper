# PeerPnrpStartup function

## Description

The **PeerPnrpStartup** function starts the Peer Name Resolution Protocol (PNRP) service for the calling peer.

## Parameters

### `wVersionRequested`

The version of PNRP to use for this service instance. The default value is PNRP_VERSION (2).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_UNSUPPORTED_VERSION** | The provided version is unsupported. |
| **PEER_E_SERVICE_NOT_AVAILABLE** | The Peer Collaboration infrastructure, which includes People Near Me, is not available. This code will also be returned whenever an attempt is made to utilize the Collaboration infrastructure from an elevated process. |

## Remarks

To shutdown the PNRP service for the calling peer and release all resources associated with it, call [PeerPnrpShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpshutdown).

## See also

[PeerPnrpShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpshutdown)