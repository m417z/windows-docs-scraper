# DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT callback function

## Description

 The DirectX graphics kernel subsystem calls a WDDM 1.3 driver's **DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT** callback routine to check the details of hardware support for multiplane overlays. This function has been replaced with [**DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3).

## Parameters

### `hAdapter`

A handle to a context block that is associated with a display adapter. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCheckMultiPlaneOverlaySupport`

A pointer to a [**DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport) structure that provides details on hardware support for multiplane overlays.

## Return value

**DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT** returns STATUS_SUCCESS if it succeeds; otherwise it returns one of the error codes defined in *Ntstatus.h*.

## See also

[**DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport)

[**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)