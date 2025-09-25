# IOfflineFilesFileItem::IsSparse

## Description

Determines whether an item in the Offline Files cache is sparsely cached.

## Parameters

### `pbIsSparse` [out]

Receives **TRUE** if the item is sparsely cached, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

A sparsely cached item is an item that has an entry in the Offline Files cache but is not completely cached; not all of its data blocks have been read into the cache. Such items must first be filled before they are available for offline use. The Offline Files service automatically fills sparse files on a frequent schedule.

To fill sparse files manually, use the [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize) method, setting the OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE control flag in the *dwSyncControl* parameter.

## See also

[IOfflineFilesFileItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfileitem)