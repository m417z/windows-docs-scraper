# IOfflineFilesEvents::SyncFileResult

## Description

Reports the result of synchronizing a particular file.

## Parameters

### `rSyncId` [in]

Unique identifier for the synchronization operation that generated this event. Provided by the caller of the [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize), [IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin), or [IOfflineFilesCache::Unpin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-unpin) method. This is GUID_NULL if no ID was provided.

### `pszFile` [in]

Fully qualified UNC path of the processed file.

### `hrResult` [in]

Result of the sync operation on this file. The parameter will contain S_OK if the operation completed successfully or a value otherwise.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)