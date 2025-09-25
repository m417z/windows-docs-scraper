# PeerDistClientOpenContent function

## Description

The **PeerDistClientOpenContent** function opens and returns a PEERDIST_CONTENT_HANDLE. The client uses the content handle to retrieve data from the Peer Distribution service.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `pContentTag` [in]

Pointer to a [PEERDIST_CONTENT_TAG](https://learn.microsoft.com/windows/win32/api/peerdist/ns-peerdist-peerdist_content_tag) structure that contains a 16 byte client specified identifier. This parameter is used in conjunction with the [PeerDistClientFlushContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientflushcontent) function.

### `hCompletionPort` [in, optional]

A handle to the completion port that can be used for retrieving the completion notification of the asynchronous function. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function This parameter can be **NULL**.

### `ulCompletionKey` [in, optional]

Value to be returned through the *lpCompletionKey* parameter of the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This parameter is ignored when *hCompletionPort* is **NULL**.

### `phContentHandle` [out]

A pointer to a variable that receives the **PEERDIST_CONTENT_HANDLE** used to retrieve or add data.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

Client must call the **PeerDistClientOpenContent** function to obtain a **PEERDIST_CONTENT_HANDLE** handle that later can be used in the following functions:

* [PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation)
* [PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation)
* [PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread)
* [PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread)
* [PeerDistClientAddData](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientadddata)

If an optional completion port handle is specified, it is used for posting the completion results of above listed asynchronous functions.

The handle returned by **PeerDistClientOpenContent** function call must be closed by [PeerDistClientCloseContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientclosecontent) function.

## See also

[PeerDistClientAddContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientaddcontentinformation)

[PeerDistClientAddData](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientadddata)

[PeerDistClientBlockRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientblockread)

[PeerDistClientCloseContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientclosecontent)

[PeerDistClientCompleteContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientcompletecontentinformation)

[PeerDistClientFlushContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientflushcontent)

[PeerDistClientStreamRead](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientstreamread)

[PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup)