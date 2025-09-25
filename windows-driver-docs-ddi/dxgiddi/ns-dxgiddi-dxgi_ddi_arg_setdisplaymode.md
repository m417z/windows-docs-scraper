# DXGI_DDI_ARG_SETDISPLAYMODE structure

## Description

The DXGI_DDI_ARG_SETDISPLAYMODE structure describes parameters for setting the display mode.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver sets the display mode. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `hResource` [in]

A handle to the resource that contains the display surface.

### `SubResourceIndex` [in]

The zero-based index into the resource, which the handle in the **hResource** member specifies. The **SubResourceIndex** index indicates the display surface.

## See also

[SetDisplayModeDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)