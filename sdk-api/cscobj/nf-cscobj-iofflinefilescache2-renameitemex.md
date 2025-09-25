# IOfflineFilesCache2::RenameItemEx

## Description

Renames an item in the cache. This method is identical to the [IOfflineFilesCache::RenameItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-renameitem) method, except that it will attempt to do the rename operation right away.

## Parameters

### `pszPathOriginal` [in]

Fully qualified UNC path of the item (server, share, file or directory) to be renamed.

### `pszPathNew` [in]

The new path to replace *pszPathOriginal* if the item that *pszPathOriginal* points to exists in the cache.

### `bReplaceIfExists` [in]

This parameter is reserved for future use.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This method does not require system administrator privilege.

If the item to be renamed is a file or directory, it must obey the file system semantics for the rename operation. If the file or a child file (for a directory) is already open, the rename will fail. Also, this method attempts to perform the rename as long as the user has access to the item that is being renamed.

If you need to minimize the chance that the item is in use, call the [IOfflineFilesCache::RenameItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-renameitem) method instead.

## See also

[IOfflineFilesCache2](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache2)