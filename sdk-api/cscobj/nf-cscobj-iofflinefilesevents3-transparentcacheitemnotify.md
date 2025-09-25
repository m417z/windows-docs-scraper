# IOfflineFilesEvents3::TransparentCacheItemNotify

## Description

Reports that an action has been performed on a transparently cached item.

## Parameters

### `pszPath` [in]

The item's UNC path string.

### `EventType` [in]

An [OFFLINEFILES_EVENTS](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_events) enumeration value that indicates the type of the item.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

### `bModifiedData` [in]

**TRUE** if the item's data was modified, **FALSE** otherwise.

### `bModifiedAttributes` [in]

**TRUE** if one or more of the item's attributes were modified, **FALSE** otherwise.

### `pzsOldPath` [in]

The original UNC path string for the item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesEvents3](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents3)

[IOfflineFilesTransparentCacheInfo::IsTransparentlyCached](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilestransparentcacheinfo-istransparentlycached)