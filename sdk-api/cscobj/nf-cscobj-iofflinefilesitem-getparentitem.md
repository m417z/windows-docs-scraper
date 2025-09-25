# IOfflineFilesItem::GetParentItem

## Description

Retrieves the [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) interface for the parent of the item. This method can be called repeatedly to retrieve items at the top of the cache namespace.

## Parameters

### `ppItem` [out]

Receives the address of the [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) interface of the parent item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

If the item is a server item, this function returns `HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)`. Server items are at the top of the Offline Files cache namespace and do not have a parent item. The parent of a server item is the cache itself. This is represented by the fact that an instance of [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) is also a container of server items.

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)