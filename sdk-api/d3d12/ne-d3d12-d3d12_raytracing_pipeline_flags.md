## Description

Defines constants that specify configuration flags for a raytracing pipeline.

## Constants

### `D3D12_RAYTRACING_PIPELINE_FLAG_NONE:0`

Specifies no option.

### `D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_TRIANGLES:0x100`

Specifies that for any **TraceRay** call within this raytracing pipeline, the [RAY_FLAG_SKIP_TRIANGLES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_ray_flags) ray flag should be added in. The resulting combination of ray flags must be valid. The presence of this flag in a raytracing pipeline config doesn't show up in a **RayFlags** call from a shader. Implementations might be able to optimize pipelines knowing that a particular primitive type need not be considered.

### `D3D12_RAYTRACING_PIPELINE_FLAG_SKIP_PROCEDURAL_PRIMITIVES:0x200`

Specifies that for any **TraceRay** call within this raytracing pipeline, the [RAY_FLAG_SKIP_PROCEDURAL_PRIMITIVES](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_ray_flags) ray flag should be added in.

## Remarks

## See also