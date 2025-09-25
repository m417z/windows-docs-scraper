# PeerDistClientCompleteContentInformation function

## Description

The **PeerDistClientCompleteContentInformation** function completes the process of adding the content information.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentHandle` [in]

A **PEERDIST_CONTENT_HANDLE** returned by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

Upon completion of this function, a client can call [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) or [PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread) to retrieve the data from the Peer Distribution system.

## See also

[PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)