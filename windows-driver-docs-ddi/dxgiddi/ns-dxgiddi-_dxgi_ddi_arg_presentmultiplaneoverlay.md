# _DXGI_DDI_ARG_PRESENTMULTIPLANEOVERLAY structure

## Description

Specifies a multiplane overlay resource to display.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver performs the presentation. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `pDXGIContext` [in]

A handle to the DXGI context. This handle is opaque to the driver. The driver should assign the handle in this member to the **pDXGIContext** member of the [DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present_multiplane_overlay) structure when the driver calls the [pfnPresentMultiPlaneOverlayCb (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb) function.

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input that is to be displayed.

### `Flags` [in]

A [DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags) structure that identifies, in bit-field flags, how to display.

### `FlipInterval` [in]

A value of type [DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type) that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `PresentPlaneCount` [in]

The number of overlay planes that are available to display.

### `pPresentPlanes` [in]

A pointer to a structure of type [DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_present_multiplane_overlay) that describes the overlay plane to display.

### `Reserved`

This member is reserved and should be set to zero.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice)

[DXGIDDICB_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present_multiplane_overlay)

[DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type)

[DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags)

[DXGI_DDI_PRESENT_MULTIPLANE_OVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-_dxgi_ddi_present_multiplane_overlay)

[pfnPresentMultiPlaneOverlayCb (DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_present_multiplane_overlaycb)