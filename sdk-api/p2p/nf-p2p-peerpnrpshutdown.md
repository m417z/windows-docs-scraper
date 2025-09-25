# PeerPnrpShutdown function

## Description

The **PeerPnrpShutdown** function shuts down a running instance of the Peer Name Resolution Protocol (PNRP) service and releases all resources associated with it.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **PEER_E_NOT_INITIALIZED** | The Windows Peer infrastructure is not initialized. Calling the relevant initialization function is required. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |

## See also

[PeerPnrpStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartup)