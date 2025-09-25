# IOfflineFilesCache::FindItemEx

## Description

Locates a particular file or directory item in the cache.

## Parameters

### `pszPath` [in]

UNC path of the file or directory to be located.

### `pIncludeFileFilter` [in]

If provided, references the filter applied to the decision to include files. This parameter is optional and can be **NULL**.

### `pIncludeDirFilter` [in]

If provided, references the filter applied to the decision to include directories. This parameter is optional and can be **NULL**.

### `pExcludeFileFilter` [in]

If provided, references the filter applied to the decision to exclude files. This parameter is optional and can be **NULL**.

### `pExcludeDirFilter` [in]

If provided, references the "filter" applied to the decision to exclude directories. This parameter is optional and may be **NULL**.

### `dwQueryFlags` [in]

Flags affecting the amount of query activity at the time the item is located in the cache. The parameter can contain one or more of the following bit flags.

#### OFFLINEFILES_ITEM_QUERY_REMOTEINFO (0x00000001)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE (0x00000002)

If this flag is set, the find operation includes an extra call to the Offline Files store to obtain information about the connection state (online or offline) of the item. If this flag is not set, the operation does not include this extra operation, and connection state will be queried on demand when it is requested.

**Note** If you know that you will need connection state for the item, setting this flag is slightly more efficient. If connection state is not required, it is more efficient to not set this flag.

#### OFFLINEFILES_ITEM_QUERY_LOCALDIRTYBYTECOUNT (0x00000004)

If this flag is set, the find operation includes an extra call to the Offline Files store to obtain information about the amount, in bytes, of unsynchronized ("dirty") data for the associated file in the local Offline Files cache.

#### OFFLINEFILES_ITEM_QUERY_REMOTEDIRTYBYTECOUNT (0x00000008)

This flag is reserved for future use.

#### OFFLINEFILES_ITEM_QUERY_INCLUDETRANSPARENTCACHE (0x00000010)

If this flag is set, the find operation includes transparently cached items.

#### OFFLINEFILES_ITEM_QUERY_ADMIN (0x80000000)

Allows administrators to find items cached by any user. If this flag is set and the caller is not an administrator, the method call fails.

### `ppItem` [out]

Pointer to the [IOfflineFilesItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesitem) interface of the cache item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)` if the cache entry is not found.

## Remarks

**FindItemEx** is an enhanced version of [FindItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-finditem) that provides filtering capabilities similar to what is offered by cache item enumeration. Calling **FindItem** is equivalent to calling **FindItemEx** with all four filter parameters set to **NULL**.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)