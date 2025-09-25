# IOfflineFilesSyncErrorInfo::GetSyncOperation

## Description

Retrieves a value indicating the type of sync operation that was being performed when the error was encountered.

## Parameters

### `pSyncOp` [out]

Receives a value from the [OFFLINEFILES_SYNC_OPERATION](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_sync_operation) enumeration that indicates the operation type.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerrorinfo)