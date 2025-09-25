# IOfflineFilesShareInfo::IsShareDfsJunction

## Description

Determines whether the share item is a DFS junction or a shared folder on a server.

## Parameters

### `pbIsDfsJunction` [out]

Receives **TRUE** if the item is a DFS junction, or **FALSE** if the share is a shared folder (\\server\share) on a server.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesShareInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesshareinfo)