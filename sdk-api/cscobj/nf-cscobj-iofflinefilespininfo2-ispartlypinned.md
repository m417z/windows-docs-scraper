# IOfflineFilesPinInfo2::IsPartlyPinned

## Description

Determines whether the item is partly pinned.

## Parameters

### `pbPartlyPinned` [out]

Receives **TRUE** if the item has some child content that is pinned in the Offline Files cache, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Only container items, such as directories and shares, can be partly pinned. An item is partly pinned if the item itself is not pinned, but it contains pinned items. The item could contain autocached or transparently cached items in addition to the pinned items.

## See also

[IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin)

[IOfflineFilesGhostInfo::IsGhosted](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesghostinfo-isghosted)

[IOfflineFilesPinInfo2](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilespininfo2)

[IOfflineFilesTransparentCacheInfo::IsTransparentlyCached](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilestransparentcacheinfo-istransparentlycached)