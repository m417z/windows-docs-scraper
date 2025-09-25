# IOfflineFilesCache::ProcessAdminPinPolicy

## Description

Causes Offline Files to process the "administratively assigned offline files" group policy.

## Parameters

### `pPinProgress` [in]

Pointer to the [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) interface that receives progress notifications as items are being pinned in the Offline Files cache.

### `pUnpinProgress` [in]

Pointer to the [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) interface that receives progress notifications as items are being unpinned from the Offline Files cache.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The "administratively assigned offline files" group policy provides a way for administrators to cause specific folders to be pinned by Offline Files for specific users by way of the Group Policy mechanism. The primary client of this function is the Offline Files Group Policy extension. In most deployments there is no need to call this function. The Group Policy extension will do that for you.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)