# IOfflineFilesSyncErrorInfo::InfoAvailable

## Description

Indicates whether information was obtained for the local, remote, or original copy of the item during synchronization.

## Parameters

### `pbLocalInfo` [out]

Receives **TRUE** if information was obtained for the local copy of the item during synchronization, or **FALSE** otherwise. If **TRUE**, [GetLocalInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncerrorinfo-getlocalinfo) can be called to retrieve the information.

### `pbRemoteInfo` [out]

Receives **TRUE** if information was obtained for the remote copy of the item during synchronization, or **FALSE** otherwise. If **TRUE**, [GetRemoteInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncerrorinfo-getremoteinfo) can be called to retrieve the information.

### `pbOriginalInfo` [out]

Receives **TRUE** if information was obtained for the original copy of the item during synchronization, or **FALSE** otherwise. If **TRUE**, [GetOriginalInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncerrorinfo-getoriginalinfo) can be called to retrieve the information.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerrorinfo)