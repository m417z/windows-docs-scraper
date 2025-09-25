# IOfflineFilesItem::GetItemType

## Description

Returns a type code identifying the type of the item: server, share, directory, or file.

## Parameters

### `pItemType` [out]

Receives an [OFFLINEFILES_ITEM_TYPE](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_type) enumeration value that indicates the type of the item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Another way to determine an item's type is to query the item for one of the following type-specific interfaces:

[IOfflineFilesDirectoryItem](https://learn.microsoft.com/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesdirectoryitem)
[IOfflineFilesFileItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfileitem)
[IOfflineFilesServerItem](https://learn.microsoft.com/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesserveritem)
[IOfflineFilesShareItem](https://learn.microsoft.com/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesshareitem)
If the call to [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) succeeds, the item is of the requested type. An item can be of only one of the above types.

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)