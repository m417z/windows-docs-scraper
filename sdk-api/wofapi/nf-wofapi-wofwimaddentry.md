# WofWimAddEntry function

## Description

Adds a single WIM data source to a volume such that files can be created on the volume which are stored within the WIM.

## Parameters

### `VolumeName` [in]

The path to the volume upon which files residing in the WIM should be created.

### `WimPath` [in]

The path to the WIM file which should be used to provide data to files.

### `WimType` [in]

The type of WIM. Can be **WIM_BOOT_OS_WIM** or **WIM_BOOT_NOT_OS_WIM**.

### `WimIndex` [in]

Index of the image in the WIM which is applied.

### `DataSourceId` [out]

On successful return, contains the data source used to identify the entry. This data source can be used to create new files with [WofSetFileDataLocation](https://learn.microsoft.com/windows/desktop/api/wofapi/nf-wofapi-wofsetfiledatalocation).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FSCTL_ADD_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)