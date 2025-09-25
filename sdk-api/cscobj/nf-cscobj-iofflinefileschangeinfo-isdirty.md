# IOfflineFilesChangeInfo::IsDirty

## Description

Determines whether an item in the Offline Files cache has been modified.

## Parameters

### `pbDirty` [out]

Receives **TRUE** if the item has been modified in some way while working offline, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

When an item is modified offline, it is marked as "dirty." Such items must be synchronized to clear this "dirty" property on the item. The Offline Files service automatically synchronizes items when an offline scope transitions to online.

## See also

[IOfflineFilesChangeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileschangeinfo)