# IOfflineFilesPinInfo::IsPinned

## Description

Determines whether the item is pinned.

## Parameters

### `pbPinned` [out]

Receives **TRUE** if the item is pinned for any reason, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

When an item is pinned in the Offline Files cache, it is protected from automatic eviction and is guaranteed to be available offline.

## See also

[IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin)

[IOfflineFilesPinInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilespininfo)