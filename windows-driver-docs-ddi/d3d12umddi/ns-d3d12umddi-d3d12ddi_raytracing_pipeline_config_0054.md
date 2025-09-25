# D3D12DDI_RAYTRACING_PIPELINE_CONFIG_0054 structure

## Description

Describes a ray tracing pipeline configuration.

## Members

### `MaxTraceRecursionDepth`

The limit on ray recursion for the ray tracing pipeline.

## Remarks

A ray tracing pipeline needs one ray tracing pipeline configuration. If multiple pipeline configurations are present they must all match in content. There isn’t benefit to having this duplication. For example, defining it once per collection doesn’t help drivers do early shader compilation before creating a ray tracing pipeline. This is unlike [D3D12DDI_RAYTRACING_SHADER_CONFIG_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_shader_config_0054), which does benefit from duplication per collection.

## See also