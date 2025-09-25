# IOfflineFilesDirtyInfo::LocalDirtyByteCount

## Description

Retrieves the amount of unsynchronized ("dirty") data for the associated file in the local Offline Files cache.

## Parameters

### `pDirtyByteCount` [out]

The number of bytes of unsynchronized data.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

This method can be called only for file items, which are represented by [IOfflineFilesFileItem](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesfileitem) objects.

## See also

[IOfflineFilesDirtyInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesdirtyinfo)