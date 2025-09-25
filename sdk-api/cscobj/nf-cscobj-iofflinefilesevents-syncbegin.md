# IOfflineFilesEvents::SyncBegin

## Description

Reports that the Offline Files cache has begun a synchronization operation.

## Parameters

### `rSyncId` [in]

Unique identifier for the synchronization operation that generated this event. Provided by the caller of the [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize), [IOfflineFilesCache::Pin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-pin), or [IOfflineFilesCache::Unpin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-unpin) method. This is GUID_NULL if no ID was provided.

## Return value

The return value is ignored.

## Remarks

The synchronization engine is also used to encrypt the Offline Files cache. Therefore, encryption and unencryption operations will also cause this event to be generated.

## See also

[IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)