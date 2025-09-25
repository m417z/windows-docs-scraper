# IOfflineFilesEvents::SyncEnd

## Description

Reports that the Offline Files cache has ended a synchronize operation.

## Parameters

### `rSyncId` [in]

Unique identifier for the synchronization operation that generated this event. Provided by the caller of the [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize), [IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin), or [IOfflineFilesCache::Unpin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-unpin) method. This is GUID_NULL if no ID was provided.

### `hrResult` [in]

Result value indicating the reason for the end of the sync operation. This parameter will be S_OK if the operation completed successfully, HRESULT_FROM_WIN32(ERROR_CANCELLED) if the operation was aborted and an error value if some other failure caused the operation to complete prematurely.

## Return value

The return value is ignored.

## Remarks

The sync engine is also used to encrypted the Offline Files cache. Therefore, an encryption or unencryption operation will cause this event to be generated.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)