# WIM_PROVIDER_UPDATE_OVERLAY_INPUT structure

## Description

The current Windows Image File (WIM) data source is updated with a new WIM file using the [**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay) control request with a **WIM_PROVIDER_UPDATE_OVERLAY_INPUT** structure.

## Members

### `DataSourceId`

An identifier value for the WIM file data source to update.

### `WimFileNameOffset`

The offset, in bytes, from the beginning of this structure of the file name for the WIM file to add as a backing source. The file name is a string of **WCHAR** character values.

### `WimFileNameLength`

The length, in bytes, of the file name at found at **WimFileNameOffset**.

## Remarks

The WIM file name is included immediately following **WIM_PROVIDER_UPDATE_OVERLAY_INPUT** in the system buffer for a [**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay) control request. The **WimFileNameOffset** member is set to **sizeof**(**WIM_PROVIDER_UPDATE_OVERLAY_INPUT**).

The WIM file name includes a terminating NULL character. **WimFileNameLength** contains the length of the file name excluding the terminating NULL.

## See also

[**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)

[**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)

[**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)

[**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay)