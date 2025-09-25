# IOfflineFilesEvents::ItemRenamed

## Description

Reports that the path for an item in the Offline Files cache has been renamed.

## Parameters

### `pszOldPath` [in]

Original UNC path string for the item.

### `pszNewPath` [in]

New UNC path string for the item.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

## Return value

The return value is ignored.

## Remarks

This event is sent whenever a server, share, directory or file is renamed in the cache. Note that this is a rename resulting from a file system rename operation, not from [IOfflineFilesCache::RenameItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-renameitem) or [IOfflineFilesCache2::RenameItemEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache2-renameitemex). (The rename in response to **RenameItem** or **RenameItemEx** is performed on system startup by the Offline Files driver before the Offline Files service is operational.)

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)