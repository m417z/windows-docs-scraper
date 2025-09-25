## Description

Raytracing pipeline flag.

## Constants

### `D3D12DDI_RAYTRACING_PIPELINE_FLAG_NONE`

No additional ray flags.

### `D3D12DDI_RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES`

For any [**TraceRay**](https://learn.microsoft.com/windows/win32/direct3d12/traceray-function) call within this raytracing pipeline, add in the RAY_FLAG_SKIP_TRIANGLES Ray flag. The resulting combination of ray flags must be valid. Implementations may be able to optimize pipelines knowing that a particular primitive type need not be considered.

### `D3D12DDI_RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES`

For any [**TraceRay**](https://learn.microsoft.com/windows/win32/direct3d12/traceray-function) call within this raytracing pipeline, add in the RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES Ray flag. The resulting combination of ray flags must be valid. Implementations may be able to optimize pipelines knowing that a particular primitive type need not be considered.

## Remarks

A **D3D12DDI_RAYTRACING_PIPELINE_FLAGS** value is specified in [**D3D12DDI_RAYTRACING_PIPELINE_CONFIG_0075**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_pipeline_config_0075).

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDI_RAYTRACING_PIPELINE_CONFIG_0075**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_pipeline_config_0075)