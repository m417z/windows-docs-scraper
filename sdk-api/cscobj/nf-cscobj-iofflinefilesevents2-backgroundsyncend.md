# IOfflineFilesEvents2::BackgroundSyncEnd

## Description

Reports that the Offline Files service completed a background synchronization pass.

## Parameters

### `dwSyncControlFlags` [in]

One or more OFFLINEFILES_SYNC_CONTROL_FLAG_XXXXXX flags describing the purpose of the sync operation. These may be used to determine if the sync is a one-way or two-way sync. These flags are described in the *dwSyncControl* parameter of the [IOfflineFilesCache::Synchronize](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilescache-synchronize) method.

## Return value

The return value is ignored.

## See also

[IOfflineFilesEvents2](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents2)