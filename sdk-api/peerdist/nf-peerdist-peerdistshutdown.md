# PeerDistShutdown function

## Description

The **PeerDistShutdown** function releases resources allocated by a call to [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup). Each handle returned by a **PeerDistStartup** call must be closed by a matching call to **PeerDistShutdown**

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |

## Remarks

This function will remove all publications that were created with the specified *hPeerDist* handle. It is recommended that this function is called after all pending operations have completed, as **PeerDistShutdown** cancel all pending Peer Distribution client and server operations associated with the supplied **PEERDIST_INSTANCE_HANDLE**.

## See also

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)