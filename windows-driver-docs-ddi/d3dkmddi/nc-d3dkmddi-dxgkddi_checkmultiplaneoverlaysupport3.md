# DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3 callback function

## Description

In WDDM 2.1 and later versions, the DirectX graphics kernel subsystem calls a driver's **DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3** callback routine to determine whether a specific multi-plane overlay configuration is supported. It must be implemented by WDDM 2.1 and later version drivers that support multi-plane overlays.

## Parameters

### `hAdapter`

Identifies the adapter containing the overlay hardware. The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the **MiniportDeviceContext** output parameter of the [**DxgkDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pCheckMultiPlaneOverlaySupport`

A pointer to a [DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport3) structure that describes the surfaces and display options to present.

## Return value

**DXGKDDI_CHECKMULTIPLANEOVERLAYSUPPORT3** returns the following values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The routine has successfully completed. |

## Remarks

The kernel mode driver reports whether the specified configuration is supported. The kernel mode driver should not raise or lower the available bandwidth in anticipation to this configuration getting set.

This function is always called at PASSIVE level.

## See also

[DXGKARG_CHECKMULTIPLANEOVERLAYSUPPORT3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_checkmultiplaneoverlaysupport3)