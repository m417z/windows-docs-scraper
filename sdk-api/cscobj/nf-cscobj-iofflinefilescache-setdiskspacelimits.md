# IOfflineFilesCache::SetDiskSpaceLimits

## Description

Sets disk space usage limits on the Offline Files cache.

## Parameters

### `cbLimit` [in]

Specifies the limit on the maximum amount of bytes that can be stored in the Offline Files cache.

### `cbUnpinnedLimit` [in]

Specifies the limit on the maximum amount of bytes that can be stored in the Offline Files cache for automatically cached files.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The caller must be an administrator on the local machine.

The current disk space limits may be obtained by calling [IOfflineFilesCache::GetDiskSpaceInformation](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-getdiskspaceinformation).

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)