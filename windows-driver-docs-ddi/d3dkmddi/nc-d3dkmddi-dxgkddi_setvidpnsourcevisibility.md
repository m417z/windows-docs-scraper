# DXGKDDI_SETVIDPNSOURCEVISIBILITY callback function

## Description

The *DxgkDdiSetVidPnSourceVisibility* function programs the video output codec that is associated with a specified video present source to either start scanning or stop scanning the source's primary surface.

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the Microsoft DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pSetVidPnSourceVisibility`

A pointer to a [DXGKARG_SETVIDPNSOURCEVISIBILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourcevisibility) structure that contains function arguments.

## Return value

*DxgkDdiSetVidPnSourceVisibility* returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

See requirements on calling this function with multiplane overlays in [Multiplane overlay VidPN presentation](https://learn.microsoft.com/windows-hardware/drivers/display/multiplane-overlay-vidpn-presentation).

*DxgkDdiSetVidPnSourceVisibility* should be made pageable.

## See also

[DxgkDdiSetVidPnSourceAddress](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560767(v=vs.85))