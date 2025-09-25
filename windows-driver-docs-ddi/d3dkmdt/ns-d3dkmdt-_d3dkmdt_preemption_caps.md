# _D3DKMDT_PREEMPTION_CAPS structure

## Description

Specifies the capabilities for the preemption of graphic processing unit (GPU) graphics requests that the display miniport driver supports.

## Members

### `GraphicsPreemptionGranularity`

A [D3DKMDT_GRAPHICS_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_graphics_preemption_granularity) value that specifies the level of graphics requests that the driver can preempt for GPU graphics operations.

### `ComputePreemptionGranularity`

A [D3DKMDT_COMPUTE_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_compute_preemption_granularity) value that specifies the level of graphics requests that the driver can preempt for GPU compute shader operations.

## See also

[D3DKMDT_COMPUTE_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_compute_preemption_granularity)

[D3DKMDT_GRAPHICS_PREEMPTION_GRANULARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_graphics_preemption_granularity)

[DXGK_DRIVERCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)