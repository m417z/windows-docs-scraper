# PeerDistServerCloseContentInformation function

## Description

The **PeerDistServerCloseContentInformation** function closes the handle opened by [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation).

## Parameters

### `hPeerDist` [in]

The **PEERDIST_INSTANCE_HANDLE** returned by [PeerDistStartup](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdiststartup).

### `hContentInfo` [in]

The handle returned by [PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation).

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**. Otherwise, the function may return one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE** | The provided *hPeerDist* or *hContentInfo* handles are invalid. |
| **ERROR_ACCESS_DISABLED_BY_POLICY** | The feature is disabled by Group Policy. |

## Remarks

The **PeerDistServerCloseContentInformation** closes the **PEERDIST_CONTENTINFO_HANDLE**. Additionally, calling **PeerDistServerCloseContentInformation** will cancel any pending operations associated with the **PEERDIST_CONTENTINFO_HANDLE**.

## See also

[PeerDistServerOpenContentInformation](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistserveropencontentinformation)