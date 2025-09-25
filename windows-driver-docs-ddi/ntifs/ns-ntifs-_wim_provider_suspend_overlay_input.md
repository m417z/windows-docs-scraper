# WIM_PROVIDER_SUSPEND_OVERLAY_INPUT structure

## Description

The **WIM_PROVIDER_SUSPEND_OVERLAY_INPUT** structure specifies a Windows Image File (WIM) data source to suspend from the WIM provider using the [**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay) control request.

## Members

### `DataSourceId`

An identifier value for the WIM file data source to suspend.

## See also

[**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)

[**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)

[**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)

[**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay)