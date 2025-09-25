## Description

The **D3DKMDT_VIRTUALGPUSURFACEDATA** structure describes a surface allocated for a virtual GPU (vGPU).

## Members

### `Size`

Size in bytes of the surface.

### `Alignment`

The alignment requirement of the surface, in bytes.

### `DriverSegmentId`

The identifier of the driver segment that contains the surface.

### `PrivateDriverData`

The private driver data associated with the surface.

## Remarks

## See also

[**DXGKARG_GETSTANDARDALLOCATIONDRIVERDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_getstandardallocationdriverdata)

[**DxgkDdiGetStandardAllocationDriverData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getstandardallocationdriverdata)