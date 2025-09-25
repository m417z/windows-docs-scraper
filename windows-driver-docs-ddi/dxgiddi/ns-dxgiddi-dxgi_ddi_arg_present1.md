# DXGI_DDI_ARG_PRESENT1 structure

## Description

Describes a resource to display. Used with the [pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions) function by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Members

### `hDevice` [in]

A handle to the display device (graphics context) on which the driver performs the presentation. The Direct3D runtime passes this handle to the driver in the **hDrvDevice** member of the [D3D10DDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createdevice) structure when the runtime calls the driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create the display device.

### `phSurfacesToPresent` [in]

An array of non-**NULL** handles and zero-based indices to the source resource to display or to release. **phSurfacesToPresent** is always a valid handle for a resource to display.

### `SurfacesToPresent` [in]

The array of surfaces to be presented. Must not be zero.

### `hDstResource` [in]

A handle to the destination resource to display to. **hDstResource** can be **NULL** if the destination is unknown; kernel mode will determine the destination just before sending the hardware command stream through DMA to the graphics processor.

When many resource are being presented, **hDstResource** will be **NULL**, and the driver must only translate the last source resource handle for use with the [pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb) function.

### `DstSubResourceIndex` [in]

The zero-based index into the destination resource, which the handle in the **hDstResource** member specifies. The **DstSubResourceIndex** index indicates the subresource or surface to display to.

### `pDXGIContext` [in]

A handle to the DXGI context. This handle is opaque to the driver. The driver must pass the handle in this member as the **pDXGIContext** member of the [DXGIDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present) structure when the driver calls the [pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb) function.

### `Flags` [in]

A [DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags) structure that identifies, in bit-field flags, how to perform the present operation.

### `FlipInterval` [in]

A [DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type)-typed value that indicates the flip interval (that is, if the flip occurs after zero, one, two, three, or four vertical syncs).

### `Reserved`

This member is reserved and should be set to zero.

### `pDirtyRects` [in]

A pointer to an array of dirty rectangles ([RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)s), relative to the source rectangle **SrcRect**, that indicate the portion of the overlay plane that has changed.

The driver can use this member to perform optimizations, though it's not required to use the dirty rectangle info. However, the driver should never fail a function call based on the provided dirty rectangles.

### `DirtyRects` [in]

The number of dirty rectangles in the array pointed to by **pDirtyRects**.

### `BackBufferMultiplicity`

The number of physical back buffer per logical back buffer.

## See also

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[DXGIDDICB_PRESENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgiddicb_present)

[DXGI_DDI_FLIP_INTERVAL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ne-dxgiddi-dxgi_ddi_flip_interval_type)

[DXGI_DDI_PRESENT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi_ddi_present_flags)

[RECT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rect)

[pfnPresent1(DXGI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/ns-dxgiddi-dxgi1_3_ddi_base_functions)

[pfnPresentCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_presentcb)

[pfnPresentCbDXGI](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_presentcb)