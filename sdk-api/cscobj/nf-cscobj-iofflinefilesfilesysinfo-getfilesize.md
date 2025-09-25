# IOfflineFilesFileSysInfo::GetFileSize

## Description

Retrieves the size of an item.

## Parameters

### `copy` [in]

An [OFFLINEFILES_ITEM_COPY](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_copy) enumeration value identifying which copy (local or remote) to retrieve the size of.

**Windows Vista:** This value must be **OFFLINEFILES_ITEM_COPY_LOCAL**.

### `pSize` [out]

Receive the size, in bytes, of the item.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesFileSysInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfilesysinfo)