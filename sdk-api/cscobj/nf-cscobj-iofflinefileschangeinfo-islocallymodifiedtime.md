# IOfflineFilesChangeInfo::IsLocallyModifiedTime

## Description

Determines whether one or more of an item's time values were modified while working offline.

## Parameters

### `pbLocallyModifiedTime` [out]

Receives **TRUE** if one or more of the item's time values were modified in the Offline Files cache while working offline, or **FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Use [IOfflineFilesFileSysInfo::GetTimes](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesfilesysinfo-gettimes) to examine the time values associated with an item.

## See also

[IOfflineFilesChangeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileschangeinfo)