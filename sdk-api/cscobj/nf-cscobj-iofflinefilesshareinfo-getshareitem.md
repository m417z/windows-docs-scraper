# IOfflineFilesShareInfo::GetShareItem

## Description

Finds the cache item representing the closest ancestor share to the item. In non-DFS scenarios this can be the \\server\share at the top of the namespace. In DFS scenarios this might be a cache directory entry that corresponds to a share in the DFS namespace.

## Parameters

### `ppShareItem` [out]

Receives the address of the [IOfflineFilesShareItem](https://learn.microsoft.com/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesshareitem) interface on the share item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesShareInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesshareinfo)