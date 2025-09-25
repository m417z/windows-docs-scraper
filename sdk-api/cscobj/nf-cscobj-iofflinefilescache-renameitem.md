# IOfflineFilesCache::RenameItem

## Description

Renames an item in the cache. This method logs a request with the Offline Files service for a path to be renamed on the next system restart.

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

This method requires system administrator privilege.

**Note** A restart of the system is necessary for the rename operation to be applied to the Offline Files cache.

This method fails if the path referenced by the *pszPathNew* parameter already exists in the Offline Files cache.

Beginning with Windows 8 and Windows Server 2012 you can also use the [IOfflineFilesCache2::RenameItemEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache2-renameitemex) method to rename an item. It does not require system administrator privilege or a system restart. However, it will fail if the item is currently in use.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)

[IOfflineFilesCache2::RenameItemEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache2-renameitemex)