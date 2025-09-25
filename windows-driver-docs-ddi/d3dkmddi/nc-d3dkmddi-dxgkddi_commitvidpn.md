# DXGKDDI_COMMITVIDPN callback function

## Description

The **DxgkDdiCommitVidPn** function makes a specified video present network (VidPN) active on a display adapter.

## Parameters

### `hAdapter`

A handle to a context block associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCommitVidPn`

A pointer to a [**DXGKARG_COMMITVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn) structure that contains function arguments.

## Return value

**DxgkDdiCommitVidPn** returns STATUS_SUCCESS upon successful completion; otherwise, it returns an appropriate NTSTATUS code such as STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY.

## Remarks

For more information about how the display miniport driver should handle calls to **DxgkDdiCommitVidPn**, see [**DXGKARG_COMMITVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn).

Beginning with Windows 8, if the display miniport driver sets the **SupportSmoothRotation** member of the [**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps) structure, it must support updating the path rotation on the adapter using the [**DxgkDdiUpdateActiveVidPnPresentPath**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath) function. The driver must always be able to set the path rotation during a call to the **DxgkDdiCommitVidPn** function.

## See also

[**DXGKARG_COMMITVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_commitvidpn)

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[**DxgkDdiUpdateActiveVidPnPresentPath**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_updateactivevidpnpresentpath)