# IOfflineFilesEvents::ItemNotAvailableOffline

## Description

Reports that an item in the Offline Files cache is no longer available for offline use should the remote copy become unavailable.

## Parameters

### `pszPath` [in]

The item's UNC path string.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

## Return value

The return value is ignored.

## Remarks

Receipt of this event does not mean the file has been removed from the cache. The event [ItemDeletedFromCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemdeletedfromcache) is sent when an item has been removed.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)