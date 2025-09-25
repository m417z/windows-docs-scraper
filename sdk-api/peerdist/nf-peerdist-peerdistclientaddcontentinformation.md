# PeerDistClientAddContentInformation function

## Description

The **PeerDistClientAddContentInformation** function adds the content information associated with a content handle opened by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentHandle` [in]

A **PEERDIST_CONTENT_HANDLE** opened by [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent).

### `cbNumberOfBytes`

Number of bytes in the *pBuffer* array.

### `pBuffer` [in]

Pointer to the buffer that contains the content information. This buffer must remain valid for the duration of the add operation. The caller must not use this buffer until the add operation is completed.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. The Internal member of [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure contains the completion status of the asynchronous operation. The Offset and OffsetHigh are reserved and must be 0.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

In order to retrieve content data from Peer Distribution service the client must add content information that it received from the content server by calling the **PeerDistClientAddContentInformation** function. When all content information data has been added, the [PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation) function must be called. Once **PeerDistClientCompleteContentInformation** is complete, the client can call [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread) or [PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread) to retrieve the data from the Peer Distribution system.

When calling this function multiple times on a single content handle, the caller must wait for each operation to complete before the next call is made.

An application is not limited to adding content information with a single **PeerDistClientAddContentInformation** API call, as it is possible to add portions of that content information as it is made available. When more content information is available, the application can again call **PeerDistClientAddContentInformation**. When the application is done adding the entire content information, it must then call [PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation).

## See also

[PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)