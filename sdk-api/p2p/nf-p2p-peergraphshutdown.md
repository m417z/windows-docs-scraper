# PeerGraphShutdown function

## Description

The **PeerGraphShutdown** function cleans up any resources allocated by the call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup). There must be a call to **PeerGraphShutdown** for each call to **PeerGraphStartup**.

## Return value

Returns S_OK if the operation succeeds; otherwise, the function returns the one of the standard error codes defined in WinError.h, or the function returns the following value:

| Return code | Description |
| --- | --- |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

When the last **PeerGraphShutdown** is called for a peer graph, all the opened peer graphs, outstanding enumeration handles, and outstanding event registration handles are automatically released.

## See also

[PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)