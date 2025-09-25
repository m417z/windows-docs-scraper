# _D3DKMDT_STAGINGSURFACEDATA structure

## Description

The D3DKMDT_STAGINGSURFACEDATA structure describes the lockable staging surface that data is transferred into from an application's back buffer.

## Members

### `Width` [in]

The width of the staging buffer, in pixels.

### `Height` [in]

The height of the staging buffer, in pixels.

### `Pitch` [out]

The width of the staging buffer, in bytes. The driver must return the pitch value because the staging buffer is lockable.

## Remarks

The D3DKMDT_STAGINGSURFACEDATA structure is passed by the Microsoft DirectX graphics kernel subsystem in a call to the display miniport driver's [DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata) function to generate a description of a lockable staging surface. The graphics subsystem calls the display miniport driver's [DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present) function to issue bit-block transfer (bitblt) requests to transfer data from an application's back buffer into the staging surface. The staging surface is then locked and read by the CPU.

A staging surface is potentially created for the present operation when a direct bit-block transfer to the primary surface is not possible (for example, in multiple-monitor or sprites cases).

This staging surface is always created as an 8-bits-per-color RGB pixel format (which is specified by the D3DDDIFMT_X8R8G8B8 value from the [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat) enumeration). Because the dimensions of the staging surface always match the dimensions of the back buffer, no stretch or shrink operation is required for the present operation to the staging surface.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DKMDT_STANDARDALLOCATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_standardallocation_type)

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiGetStandardAllocationDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)

[DxgkDdiPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_present)

[Present](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_present)