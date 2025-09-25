# IOfflineFilesSyncErrorInfo::GetOriginalInfo

## Description

Retrieves an instance of the [IOfflineFilesSyncErrorItemInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerroriteminfo) interface containing the file times, size, and attributes of the original copy of the item involved in the synchronization.

"Original" refers to the state information recorded the last time the cached item was in sync with the server.

## Parameters

### `ppInfo` [out]

Receives the address of an instance of [IOfflineFilesSyncErrorItemInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerroriteminfo) containing information about the original item copy involved in the synchronization.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerrorinfo)