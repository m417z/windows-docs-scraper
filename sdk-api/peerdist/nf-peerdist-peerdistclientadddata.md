# PeerDistClientAddData function

## Description

The **PeerDistClientAddData** function is used to supply content to the local cache. Typically this is done when data could not be found on the local network as indicated when either [PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread) or [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) complete with **ERROR_TIMEOUT** or **PEERDIST_ERROR_MISSING_DATA**.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentHandle` [in]

A **PEERDIST_CONTENT_HANDLE** returned by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

### `cbNumberOfBytes`

The number of bytes to be added to the local cache.

### `pBuffer` [in]

Pointer to the buffer that contains the data to be added to the local cache. This buffer must remain valid for the duration of the add operation. The caller must not use this buffer until the add operation is completed.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. The byte offset from the beginning of content, at which this data is being added, is specified by setting the **Offset** and **OffsetHigh** members of the [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The **OffsetHigh** member MUST be set to the higher 32 bits of the byte offset and the **Offset** member MUST be set to the lower 32 bits of the byte offset.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hContent* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

The data that has been added with this function and passed verification is available to other peers or hosted cache for download. The Peer Distribution service stores this data in its local cache.

If the API completes with **PEERDIST_ERROR_OUT_OF_BOUNDS**, this indicates that the offset specified in the overlapped structure is beyond the end of the content.

## See also

[PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread)

[PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)