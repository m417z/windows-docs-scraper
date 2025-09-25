# _D3DKMDT_GDISURFACEDATA structure

## Description

The D3DKMDT_GDISURFACEDATA structure describes surfaces that are used by GDI hardware acceleration and the Desktop Window Manager (DWM).

## Members

### `Width` [in]

The width of the surface, in pixels.

### `Height` [in]

The height of the surface, in pixels.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the surface. The following formats are supported:

D3DDDIFMT_A8B8G8R8

D3DDDIFMT_X8B8G8R8

D3DDDIFMT_A8R8G8B8

D3DDDIFMT_X8R8G8B8

D3DDDIFMT_A8

The D3DDDIFMT_A8 format is used only for D3DKMDT_GDISURFACE_STAGING and D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE staging surface types from the [D3DKMDT_GDISURFACETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype) enumeration.

### `Type` [in]

A [D3DKMDT_GDISURFACETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype)-typed value that indicates the surface type.

### `Flags` [in]

Reserved for future use. Must be zero.

### `Pitch` [out]

The width of the surface, which includes padding, in bytes. The display miniport driver must return the pitch value for all allocations of [D3DKMDT_GDISURFACETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype) type D3DKMDT_GDISURFACE_STAGING_CPUVISIBLE, D3DKMDT_GDISURFACE_EXISTINGSYSMEM, and D3DKMDT_GDISURFACE_TEXTURE_CROSSADAPTER.

## Remarks

The D3DKMDT_GDISURFACEDATA structure is passed by the Microsoft DirectX graphics kernel subsystem in a call to the display miniport driver's [DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function. This call generates a description of a surface that can be used for redirection by GDI hardware acceleration and the DWM.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMDT_GDISURFACETYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_gdisurfacetype)

[DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)