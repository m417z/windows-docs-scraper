# IOfflineFilesSyncErrorItemInfo::GetFileAttributes

## Description

Retrieves the Win32 file attributes for the item.

## Parameters

### `pdwAttributes` [out]

Receives the file attribute mask for the item. One or more of FILE_ATTRIBUTE_XXXXXX as defined in the Windows SDK. For more information, see the [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorItemInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerroriteminfo)