# IOfflineFilesSyncErrorInfo::InfoEnumerated

## Description

Indicates whether information was queried for the local, remote, or original copy of the item during synchronization.

## Parameters

### `pbLocalEnumerated` [out]

Receives **TRUE** if information was queried for the local copy of the item during synchronization, or **FALSE** otherwise.

### `pbRemoteEnumerated` [out]

Receives **TRUE** if information was queried for the remote copy of the item during synchronization, or **FALSE** otherwise.

### `pbOriginalEnumerated` [out]

Receives **TRUE** if information was queried for the original copy of the item during synchronization, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerrorinfo)