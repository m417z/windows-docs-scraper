## Description

**D3D12DDI_RAYTRACING_PIPELINE_CONFIG_0075** describes a ray tracing pipeline configuration.

## Members

### `MaxTraceRecursionDepth`

The limit on ray recursion for the ray tracing pipeline.

### `Flags`

A [**D3D12DDI_RAYTRACING_PIPELINE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_pipeline_flags) value.

## Remarks

A ray tracing pipeline needs one ray tracing pipeline configuration. If multiple shader configurations are present (such as one in each collection to enable independent driver compilation for each one) they must all match when combined into a raytracing pipeline.

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.

## See also

[**D3D12DDI_RAYTRACING_PIPELINE_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_pipeline_flags)