# IOfflineFilesCache::GetDiskSpaceInformation

## Description

Retrieves the amount of disk space used by the Offline Files cache as well as the space limits applied to cache usage.

## Parameters

### `pcbVolumeTotal` [out]

Receives the size, in bytes, of the volume hosting the Offline Files cache.

### `pcbLimit` [out]

Receives the limit on the maximum amount of bytes that can be stored in the Offline Files cache.

### `pcbUsed` [out]

Receives the current number of bytes used by all files that are pinned and automatically cached in the Offline Files cache.

### `pcbUnpinnedLimit` [out]

Receives the limit on the maximum amount of bytes that can be stored in the Offline Files cache for automatically cached files.

### `pcbUnpinnedUsed` [out]

Receives the current number of bytes used by all automatically cached files in the Offline Files cache.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The cache space limits may be adjusted by an administrator using [IOfflineFilesCache::SetDiskSpaceLimits](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-setdiskspacelimits).

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)