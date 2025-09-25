# _D3DKMDT_SHAREDPRIMARYSURFACEDATA structure

## Description

The D3DKMDT_SHAREDPRIMARYSURFACEDATA structure describes a shared primary surface.

## Members

### `Width` [in]

The width of the surface, in pixels. The driver returns the width value.

### `Height` [in]

The height of the surface, in pixels. The driver returns the height value.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the surface. The driver returns the format value.

### `RefreshRate` [in]

A [D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational) structure that indicates the refresh rate that the shared primary surface was created with.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the surface is located on.

## Remarks

Multiple processes can lock a shared primary surface. The video memory manager pins the standard allocation for the shared primary surface in video memory so the digital-to-analog converter (DAC) is guaranteed to always scan-out the appropriate data.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational)

[D3DKMDT_STANDARDALLOCATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)

[DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)