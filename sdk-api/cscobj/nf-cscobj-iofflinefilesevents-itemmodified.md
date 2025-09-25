# IOfflineFilesEvents::ItemModified

## Description

Reports that an item in the Offline Files cache has been modified.

## Parameters

### `pszPath` [in]

The item's UNC path string.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

### `bModifiedData` [in]

**TRUE** if the item's data was modified, **FALSE** otherwise.

### `bModifiedAttributes` [in]

**TRUE** if one or more of the item's attributes were modified, **FALSE** otherwise.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)