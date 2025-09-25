# PeerDistServerPublishAddToStream function

## Description

The **PeerDistServerPublishAddToStream** function adds data to the publishing stream.

## Parameters

### `hPeerDist` [in]

A PEERDIST_INSTANCE_HANDLE returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hStream` [in]

A PEERDIST_STREAM_HANDLE created by [PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream).

### `cbNumberOfBytes` [in]

Number of bytes to be published.

### `pBuffer` [in]

Pointer to the buffer that contains the data to be published. This buffer must remain valid for the duration of the add operation. The caller must not use this buffer until the add operation is completed.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. The **Offset** and **OffsetHigh** members are reserved and must be zero.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hStream* handle is invalid. |
| **ERROR_OPERATION_ABORTED** | The operation was canceled. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

When calling this function multiple times on a single stream handle, the caller must wait for each operation to complete before the next call is made.

## See also

[PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)