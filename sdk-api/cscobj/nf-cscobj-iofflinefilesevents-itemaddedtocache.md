# IOfflineFilesEvents::ItemAddedToCache

## Description

Reports that an item has been added to the Offline Files cache.

## Parameters

### `pszPath` [in]

The item's UNC path string.

### `ItemType` [in]

An [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

## Return value

The return value is ignored.

## Remarks

Note that addition to the cache does not mean that the item is available for offline use. It may still be sparsely cached. When the item is available for offline use, the [ItemAvailableOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemavailableoffline) event will be sent.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)