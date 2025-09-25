# WofWimRemoveEntry function

## Description

Removes a single WIM data source from backing files on a volume.

## Parameters

### `VolumeName` [in]

The volume name which contained files whose data was provided by the WIM.

### `DataSourceId` [in]

Identifies the WIM entry.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the volume currently has files whose data is derived from the WIM file, the data for those files will become permanently inaccessible. It is good practice to remove any files referring to the WIM file prior to removing the data source from a volume. Once all data sources for a WIM file have been removed, the WIM file itself can be renamed or deleted.

## See also

[FSCTL_REMOVE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)