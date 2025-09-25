# _DXGI_DDI_ARG_GETMULTIPLANEOVERLAYCAPS structure

## Description

Used in a call to the [pfnGetMultiPlaneOverlayCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions) function to get overlay plane capabilities.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) for which overlay plane capabilities are needed.

The Direct3D runtime passed this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when it created the device by calling the [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) routine.

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input for which the capabilities are queried.

### `MultiplaneOverlayCaps` [out]

The overlay plane capabilities, given as a [DXGI_DDI_MULTIPLANE_OVERLAY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_multiplane_overlay_caps) structure.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGI_DDI_MULTIPLANE_OVERLAY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_multiplane_overlay_caps)

[pfnGetMultiPlaneOverlayCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)