# IOfflineFilesChangeInfo::IsLocallyModifiedAttributes

## Description

Determines whether one or more of an item's attributes were modified while working offline.

## Parameters

### `pbLocallyModifiedAttributes` [out]

Receives **TRUE** if one or more of the item's attributes were modified in the Offline Files cache while working offline, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Use [IOfflineFilesFileSysInfo::GetAttributes](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesfilesysinfo-getattributes) to examine the Win32 file attributes for an item.

## See also

[IOfflineFilesChangeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileschangeinfo)