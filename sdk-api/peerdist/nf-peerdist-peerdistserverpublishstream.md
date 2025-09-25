# PeerDistServerPublishStream function

## Description

The **PeerDistServerPublishStream** function initializes a new stream to be published to the Peer Distribution service.

## Parameters

### `hPeerDist` [in]

A PEERDIST_INSTANCE_HANDLE returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `cbContentIdentifier`

The length, in bytes, of the buffer that contains content identifier data.

### `pContentIdentifier` [in]

A pointer to an array that contains a content identifier data.

### `cbContentLength`

The length, in bytes, of the content to be published. This value can be 0 if the content length is not yet known. If a non-zero argument is provided then it must match to the total data length added by [PeerDistServerPublishAddToStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishaddtostream) function calls.

### `pPublishOptions` [in, optional]

Pointer to a [PEERDIST_PUBLICATION_OPTIONS](https://learn.microsoft.com/windows/win32/api/peerdist/ns-peerdist-peerdist_publication_options) structure that specifies content publishing rules.

### `hCompletionPort` [in, optional]

A handle to the completion port that can be used for retrieving the completion notification of the asynchronous function. To create a completion port, use the [CreateIoCompletionPort](https://learn.microsoft.com/windows/desktop/FileIO/createiocompletionport) function. This parameter can be **NULL**.

### `ulCompletionKey` [in, optional]

Value returned through the *lpCompletionKey* parameter of the [GetQueuedCompletionStatus](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-getqueuedcompletionstatus) function. This parameter is ignored when *hCompletionPort* is **NULL**.

### `phStream` [out]

A pointer that receives a handle to the stream that is used to publish data into the Peer Distribution service.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The specified *hPeerDist* is invalid. |
| **PEERDIST_ERROR_ALREADY_EXISTS** | The content identifier used for publication is already published. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

A content identifier is a user defined label for the content being published. This content identifier is used for [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation), [PeerDistServerUnpublish](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverunpublish), and [PeerDistServerCancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistservercancelasyncoperation) calls.

The handle received by phStream can be used in [PeerDistServerPublishAddToStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishaddtostream) and [PeerDistServerPublishCompleteStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishcompletestream) to publish data into the Peer Distribution service. This handle should be closed by [PeerDistServerCloseStreamHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosestreamhandle).

A publication is accessible only to the User Account that originally published the content. If a different user calls **PeerDistServerPublishStream** with the same content identifier, a separate publication will be created under the context of that user.

## See also

[PeerDistServerCancelAsyncOperation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistservercancelasyncoperation)

[PeerDistServerCloseStreamHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosestreamhandle)

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation)

[PeerDistServerPublishAddToStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishaddtostream)

[PeerDistServerPublishCompleteStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishcompletestream)

[PeerDistServerUnpublish](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverunpublish)