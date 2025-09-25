# PeerDistServerCloseStreamHandle function

## Description

The **PeerDistServerCloseStreamHandle** function closes a handle returned by [PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream).

## Parameters

### `hPeerDist` [in]

A PEERDIST_INSTANCE_HANDLE returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hStream` [in]

A PEERDIST_STREAM_HANDLE returned by [PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hStream* handle is invalid |

## Remarks

The **PeerDistServerCloseStreamHandle** function call cancels all pending operations associated with *hStream*. To prevent unintended cancellation of publication and closure of the stream handle, this function should be called after the completion of [PeerDistServerPublishCompleteStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishcompletestream).

**PeerDistServerCloseStreamHandle** does not remove the publication. In order to remove the publication, call [PeerDistServerUnpublish](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverunpublish).

## See also

[PeerDistServerPublishCompleteStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishcompletestream)

[PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream)

[PeerDistServerUnpublish](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverunpublish)