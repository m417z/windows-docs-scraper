## Description

The **DXGKARG_NOTIFYWORKSUBMISSION** structure contains parameters for [**DxgkDdiNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_notifyworksubmission).

## Members

### `hHwQueue`

[in] Handle to a KMD hardware queue object, which was created using [**DxgkddiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue).

### `Flags`

[in] A bit field of [**DXGKARG_NOTIFYWORKSUBMISSION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_notifyworksubmission_flags) values that specify work submission flags.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

 [**DXGKARG_NOTIFYWORKSUBMISSION_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_notifyworksubmission_flags)

[**DxgkDdiNotifyWorkSubmission**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_notifyworksubmission)