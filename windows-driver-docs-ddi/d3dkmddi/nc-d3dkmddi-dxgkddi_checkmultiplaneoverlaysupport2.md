# DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2 callback function

## Description

The DirectX graphics kernel subsystem calls a WDDM 2.0 driver's **DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT2** callback routine to determine whether a specific multi-plane overlay configuration is supported. It must be implemented by WDDM 2.0 drivers that support multi-plane overlays. This function has been replaced with [**DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_checkmultiplaneoverlaysupport3).

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCheckMultiPlaneOverlaySupport`

A pointer to a [DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport2) structure that describes the surfaces and display options to present.

## Return value

If this routine succeeds, it returns NTSTATUS_SUCCESS. The driver should always return a success code.

## Remarks

The kernel-mode driver reports whether the specified configuration is supported. The kernel-mode driver should not raise or lower the available bandwidth in anticipation of this configuration getting set.

## See also

[DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport2)