# IOfflineFilesEvents::ItemNotPinned

## Description

Reports that an item in the Offline Files cache is no longer pinned. The item may still be available offline but it is now considered automatically cached.

## Parameters

### `pszPath` [in]

The item's UNC path string.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)