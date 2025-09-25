# PeerDistServerPublishCompleteStream function

## Description

The **PeerDistServerPublishCompleteStream** function completes the process of adding data to the stream.

## Parameters

### `hPeerDist` [in]

A PEERDIST_INSTANCE_HANDLE returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hStream` [in]

A PEERDIST_STREAM_HANDLE returned by [PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream).

### `lpOverlapped` [in]

Pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure. The **Offset** and **OffsetHigh** are reserved and must be zero.

## Return value

If the function succeeds, the return value is **ERROR_IO_PENDING**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* or *hStream* handle is invalid |
| **ERROR_OPERATION_ABORTED** | The operation was canceled. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

Once this API completes successfully, [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation) and [PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation) can be used to retrieve content information.

**PeerDistServerPublishCompleteStream** does not close *hStream*. In order to close *hStream*, call [PeerDistServerCloseStreamHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosestreamhandle).

## See also

[PeerDistServerCloseStreamHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverclosestreamhandle)

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation)

[PeerDistServerPublishAddToStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishaddtostream)

[PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream)

[PeerDistServerRetrieveContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverretrievecontentinformation)

[PeerDistServerUnpublish](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverunpublish)