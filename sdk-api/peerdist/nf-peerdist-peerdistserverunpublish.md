# PeerDistServerUnpublish function

## Description

The **PeerDistServerUnpublish** function removes a publication created via [PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream).

## Parameters

### `hPeerDist` [in]

A **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `cbContentIdentifier`

The length, in bytes, of the content identifier.

### `pContentIdentifier` [in]

Pointer to a buffer that contains the content identifier.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more parameters are invalid. |
| **ERROR_INVALID_HANDLE** | The *hPeerDist* handle is invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |
| **PEERDIST_ERROR_SERVICE_UNAVAILABLE** | The service is unavailable. |

## Remarks

The **PeerDistServerUnpublish** function cancels all pending operations on unpublished content within the Peer Distribution session that is associated with the specified *hPeerDist*. The client is still required to close previously opened handles on that content with a call to [PeerDistClientCloseContent](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientclosecontent).

A publication is accessible only to the User Account that originally published the content.

## See also

[PeerDistServerPublishStream](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserverpublishstream)