# IOfflineFilesFileSysInfo::GetAttributes

## Description

Retrieves the Win32 attributes for an item.

## Parameters

### `copy` [in]

An [OFFLINEFILES_ITEM_COPY](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_copy) enumeration value identifying which copy (local or remote) to retrieve the attributes for.

**Windows Vista:** This value must be **OFFLINEFILES_ITEM_COPY_LOCAL**.

### `pdwAttributes` [out]

Receives the file attribute mask for the item. One or more of **FILE_ATTRIBUTE_*XXXXXX*** as defined in the Windows SDK. For more information, see the [GetFileAttributes](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfileattributesa) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesFileSysInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfilesysinfo)