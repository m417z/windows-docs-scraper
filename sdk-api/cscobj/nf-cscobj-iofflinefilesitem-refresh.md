# IOfflineFilesItem::Refresh

## Description

Refreshes any data cached in the object by rereading from the Offline Files cache.

## Parameters

### `dwQueryFlags` [in]

TBD

## Return value

Returns **S_OK** if successful, or an error value otherwise.

`HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` if the file does not exist in the cache. This would happen if a file has been deleted from the cache after the file object was first created.

## Remarks

When a file object is first created, its internal data is initialized with information from the Offline Files cache. It is possible that while an object is held in memory, its true state in the cache can change at any time. Calling **Refresh** updates the object with the latest information from the Offline Files cache.

## See also

[IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem)