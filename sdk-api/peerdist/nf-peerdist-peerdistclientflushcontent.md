# PeerDistClientFlushContent function

## Description

The [PEERDIST_CONTENT_TAG](https://learn.microsoft.com/windows/win32/api/peerdist/ns-peerdist-peerdist_content_tag).

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `pContentTag` [in]

Pointer to a [PEERDIST_CONTENT_TAG](https://learn.microsoft.com/windows/win32/api/peerdist/ns-peerdist-peerdist_content_tag) structure that contains the tag supplied when [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent) is called.

### `hCompletionPort` [in, optional]

A handle to the completion port that can be used for retrieving the completion notification of the asynchronous function. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. This parameter can be **NULL**.

### `ulCompletionKey` [in, optional]

Value to be returned through the *lpCompletionKey* parameter of the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This parameter is ignored when *hCompletionPort* is **NULL**.

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-overlapped) structure. **Offset** and **OffsetHigh** are reserved and must be zero.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

The *pContentTag* is a client supplied tag passed to [PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent), which labels the content added by the client. This tag is used by the API to selectively flush content from the Peer Distribution cache.

## See also

[PEERDIST_CONTENT_TAG](https://learn.microsoft.com/windows/win32/api/peerdist/ns-peerdist-peerdist_content_tag)

[PeerDistClientOpenContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientopencontent)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)