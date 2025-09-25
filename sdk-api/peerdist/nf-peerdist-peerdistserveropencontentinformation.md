# PeerDistServerOpenContentInformation function

## Description

The **PeerDistServerOpenContentInformation** function opens a **PEERDIST_CONTENTINFO_HANDLE**. The client uses the handle to retrieve content information.

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `cbContentIdentifier`

The length, in bytes, of the content identifier.

### `pContentIdentifier` [in]

Pointer to a buffer that contains the content identifier.

### `ullContentOffset`

An offset from the beginning of the published content for which the content information handle is requested.

### `cbContentLength`

The length, in bytes, of the content (starting from the ullContentOffset) for which the content information is requested.

### `hCompletionPort` [in, optional]

A handle to the completion port used for retrieving the completion notification of the asynchronous function. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. This parameter can be **NULL**.

### `ulCompletionKey` [in, optional]

Value to be returned through the *lpCompletionKey* parameter of the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This parameter is ignored when *hCompletionPort* is **NULL**.

### `phContentInfo` [out]

A handle used to retrieve the content information.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **PEERDIST_ERROR_NOT_FOUND** | The specified content identifier data is not published. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

If function succeeds, the handle received by *phContentInfo* can be passed to the
[PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation) function to retrieve content information.
The handle must be closed via the [PeerDistServerCloseContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosecontentinformation) function.

If *ullContentOffset* and *cbContentLength* are both zero, then the content information for the whole content will be retrieved.

## See also

[PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation)