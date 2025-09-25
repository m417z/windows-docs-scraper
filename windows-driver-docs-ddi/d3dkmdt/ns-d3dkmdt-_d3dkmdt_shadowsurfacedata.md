# _D3DKMDT_SHADOWSURFACEDATA structure

## Description

The D3DKMDT_SHADOWSURFACEDATA structure describes a lockable shadow surface, which matches the primary surface in format and resolution for a given display mode.

## Members

### `Width` [in]

The width of the surface, in pixels. The driver returns the width value.

### `Height` [in]

The height of the surface, in pixels. The driver returns the height value.

### `Format` [in]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the surface. The driver returns the format value.

### `Pitch` [out]

The width of the surface, in bytes. The driver must return the pitch value because the shadow surface is lockable.

## Remarks

The D3DKMDT_SHADOWSURFACEDATA structure is passed by the Microsoft DirectX graphics kernel subsystem in a call to the display miniport driver's [DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function to generate a description of a lockable shadow surface. The DirectX graphics kernel subsystem uses the description in a call to the display miniport driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function to create the lockable shadow surface.

The CPU draws into the locked shadow surface, unlocks the shadow surface, and then issues bit-block transfer (bitblt) requests through the [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function from the shadow surface to the matched shared primary surface. Bit-block transfer requests are also issued to transfer data from a shared primary surface into the shadow surface.

A color conversion, stretch, or shrink operation is not required when copying data from or to a shadow surface because the source and destination formats and dimensions of shadow and shared primary surfaces always match.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMDT_STANDARDALLOCATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)

[DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)