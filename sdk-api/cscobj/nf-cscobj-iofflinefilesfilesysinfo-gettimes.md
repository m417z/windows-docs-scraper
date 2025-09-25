# IOfflineFilesFileSysInfo::GetTimes

## Description

Retrieves the time values associated with an item.

## Parameters

### `copy` [in]

An [OFFLINEFILES_ITEM_COPY](https://learn.microsoft.com/windows/desktop/api/cscobj/ne-cscobj-offlinefiles_item_copy) enumeration value identifying which copy (local or remote) to retrieve the time values for.

**Windows Vista:** This value must be **OFFLINEFILES_ITEM_COPY_LOCAL**.

### `pftCreationTime` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's creation time.

### `pftLastWriteTime` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's last-write time. This is the time the item's data was last written to.

### `pftChangeTime` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's last-change time. This is the time the item's data or attributes were last changed.

### `pftLastAccessTime` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's last-access time. This is the time the item was last read from or written to.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

The time values returned directly correspond to the Win32 file time values used by the NTFS file system.

## See also

[IOfflineFilesFileSysInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfilesysinfo)