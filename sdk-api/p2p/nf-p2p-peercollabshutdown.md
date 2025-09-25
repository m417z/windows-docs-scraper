# PeerCollabShutdown function

## Description

The **PeerCollabShutdown** function shuts down the Peer Collaboration infrastructure and releases any resources associated with it.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **PEER_E_NOT_INITIALIZED** | The application did not make a previous call to [PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup). |

## Remarks

A call to this function decreases the number of references to the Peer Collaboration infrastructure by 1. If the reference count equals 0, then all resources associated with the Peer Collaboration infrastructure are released.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabstartup)