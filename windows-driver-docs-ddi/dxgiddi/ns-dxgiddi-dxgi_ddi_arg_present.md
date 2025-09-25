# DXGI_DDI_ARG_PRESENT structure

## Description

The DXGI_DDI_ARG_PRESENT structure describes a resource to display.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver performs the presentation. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `hSurfaceToPresent` [in]

A handle to the source resource to display. **hSurfaceToPresent** is always a valid handle for a resource to display.

### `SrcSubResourceIndex` [in]

The zero-based index into the source resource, which the handle in the **hSurfaceToPresent** member specifies. The **SrcSubResourceIndex** index indicates the subresource or surface to display.

### `hDstResource` [in]

A handle to the destination resource to display to. **hDstResource** can be **NULL** if the destination is unknown; kernel mode will determine the destination just before sending the hardware command stream through DMA to the graphics processor.

### `DstSubResourceIndex`

 [in] The zero-based index into the destination resource, which the handle in the **hDstResource** member specifies. The **DstSubResourceIndex** index indicates the subresource or surface to display to.

### `pDXGIContext` [in]

A handle to the DXGI context. This handle is opaque to the driver. The driver must pass the handle in this member as the **pDXGIContext** member of the [DXGIDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure when the driver calls the [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) function.

### `Flags` [in]

A [DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags) structure that identifies, in bit-field flags, how to perform the present operation.

### `FlipInterval` [in]

A [DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[DXGIDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present)

[DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type)

[DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags)

[PresentDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_base_functions)

[pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb)