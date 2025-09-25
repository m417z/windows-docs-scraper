# IOfflineFilesGhostInfo::IsGhosted

## Description

Determines whether the item is ghosted.

## Parameters

### `pbGhosted` [out]

Receives **TRUE** if the item is ghosted, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

An item is said to be ghosted in the offline files cache if, when the item is offline, its name is visible to the user, but its contents are not accessible. A file or directory can be in this state for one of the following reasons:

* The item is pinned, which means that there is an entry for it in the cache. However, either the content has not yet been synchronized to the client, or it was removed from the client (due to loss of oplock or detection of stale data) when the client transitioned offline.
* The item has a sibling file or directory that is the root of a pinned namespace in the cache. When an item is pinned, its sibling items are ghosted so that the user can still see where the pinned item and its siblings are located in the online namespace even if the sibling items are not available offline.

## See also

[IOfflineFilesGhostInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesghostinfo)

[IOfflineFilesPinInfo2::IsPartlyPinned](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilespininfo2-ispartlypinned)