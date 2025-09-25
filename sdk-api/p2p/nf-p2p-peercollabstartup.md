# PeerCollabStartup function

## Description

The **PeerCollabStartup** function initializes the Peer Collaboration infrastructure.

## Parameters

### `wVersionRequested` [in]

Contains the minimum version of the Peer Collaboration infrastructure requested by the peer.

## Return value

Returns S_OK if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | There is not enough memory to support this operation. |
| **PEER_E_UNSUPPORTED_VERSION** | The requested version of the Peer Collaboration Infrastructure is not supported. |

## Remarks

This function must be called before any other peer collaboration (PeerCollab*) functions are called.

When the application no longer requires the Peer Collaboration infrastructure, it must make a corresponding call to [PeerCollabShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabshutdown). If **PeerCollabStartup** is called multiple times, there must be a separate corresponding call to **PeerCollabShutdown**. All of the components of the infrastructure are cleaned up only when the last call to **PeerCollabShutdown** occurs.

The current supported version is **1.0**. Call `MAKEWORD(1, 0)` to generate this version number WORD value.

## See also

[Peer Collaboration API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-functions)

[PeerCollabShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peercollabshutdown)