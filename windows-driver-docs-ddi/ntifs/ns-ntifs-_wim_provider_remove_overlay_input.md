# WIM_PROVIDER_REMOVE_OVERLAY_INPUT structure

## Description

The **WIM_PROVIDER_REMOVE_OVERLAY_INPUT** structure specifies a Windows Image File (WIM) data source to remove from the WIM provider.

## Members

### `DataSourceId`

An identifier value for the WIM file data source to remove.

## Remarks

The [**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay) request contains a **WIM_PROVIDER_REMOVE_OVERLAY_INPUT** structure in the system buffer as input. The value in **DataSourceId** is the data source identifier returned from a prior [**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay) control request.

## See also

[**FSCTL_ADD_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-add-overlay)

[**FSCTL_REMOVE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-remove-overlay)

[**FSCTL_SUSPEND_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-suspend-overlay)

[**FSCTL_UPDATE_OVERLAY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-update-overlay)