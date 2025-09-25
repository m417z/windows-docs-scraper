# DXGI_DDI_ARG_RESOLVESHAREDRESOURCE structure

## Description

The DXGI_DDI_ARG_RESOLVESHAREDRESOURCE structure describes the parameters that the user-mode display driver's [ResolveSharedResourceDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions) function uses to synchronize a shared surface or a GDI interoperable surface.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) that is associated with the shared surface or GDI interoperable surface. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `hResource` [in]

A handle to the surface that the driver uses as a shared surface or in GDI interoperability.

## See also

[ResolveSharedResourceDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_1_ddi_base_functions)