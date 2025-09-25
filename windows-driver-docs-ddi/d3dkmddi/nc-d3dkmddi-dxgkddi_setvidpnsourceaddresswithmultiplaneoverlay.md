# DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY callback function

> [!NOTE] This callback has been replaced by [DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)

## Description

Sets the addresses of multiple surfaces, including the Desktop Window Manager (DWM)'s swapchain, that are associated with a particular video present source. This function is used to present multiple surfaces (including the DWM’s swapchain) to the screen.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter.

The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetVidPnSourceAddressWithMultiPlaneOverlay`

A pointer to a [DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay) structure that defines multiplane overlays that are enabled for display.

## Return value

Returns **STATUS_SUCCESS** if it succeeds; otherwise it returns one of the error codes defined in Ntstatus.h.

## Remarks

See requirements on calling this function in [Multiplane overlay VidPN presentation](https://learn.microsoft.com/windows-hardware/drivers/display/multiplane-overlay-vidpn-presentation).

## See also

[DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)