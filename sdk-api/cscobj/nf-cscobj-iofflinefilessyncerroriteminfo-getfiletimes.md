# IOfflineFilesSyncErrorItemInfo::GetFileTimes

## Description

Retrieves the last-write and change times for the item.

## Parameters

### `pftLastWrite` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's last-write time value.

### `pftChange` [out]

Receives a pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the item's change time value.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[IOfflineFilesSyncErrorItemInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncerroriteminfo)