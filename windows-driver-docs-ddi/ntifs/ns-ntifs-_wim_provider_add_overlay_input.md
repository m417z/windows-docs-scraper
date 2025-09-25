# WIM_PROVIDER_ADD_OVERLAY_INPUT structure

## Description

The **WIM_PROVIDER_ADD_OVERLAY_INPUT** structure is used to add a new Windows Image File (WIM) data source to the WIM provider.

## Members

### `WimType`

The type of WIM file set as a backing source. The WIM file type is set to one of the following values.

| Value | Meaning |
| ----- | ------- |
| WIM_BOOT_OS_WIM | The WIM file contains Windows system files. |
| WIM_BOOT_NOT_OS_WIM | The WIM file contains non-operating system files. |

### `WimIndex`

The index of the image in the WIM file whose filename is specified at **WimFileNameOffset**.

### `WimFileNameOffset`

The offset, in bytes, from the beginning of this structure of the file name for the WIM file to add as a backing source. The file name is a string of **WCHAR** character values.

### `WimFileNameLength`

The length, in bytes, of the file name at found at **WimFileNameOffset**.

## Remarks

The WIM file name is included immediately following **WIM_PROVIDER_ADD_OVERLAY_INPUT** in the system buffer for a [**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay) control request. The **WimFileNameOffset** member is set to **sizeof**(WIM_PROVIDER_ADD_OVERLAY_INPUT).

The WIM file name includes a terminating NULL character. **WimFileNameLength** contains the length of the file name excluding the terminating NULL.

## See also

[**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)

[**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)

[**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)

[**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay)