# D3D12DDI_RAYTRACING_GEOMETRY_FLAGS enumeration

## Description

Specifies the ray tracing geometry flags.

## Constants

### `D3D12DDI_RAYTRACING_GEOMETRY_FLAG_NONE`

No options specified.

### `D3D12DDI_RAYTRACING_GEOMETRY_FLAG_OPAQUE`

When rays encounter this geometry, the geometry acts as if no any hit shader is present. It is recommended to use this flag liberally, as it can enable important ray processing optimizations.

> [!NOTE]
> This behavior can be overridden on a per-instance basis with [D3D12DDI_RAYTRACING_INSTANCE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_instance_flags), and on a per-ray basis using Ray flags in TraceRay().

### `D3D12DDI_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION`

By default, the system is free to trigger an any hit shader more than once for a given ray-primitive intersection. This flexibility helps improve the traversal efficiency of acceleration structures in certain cases. For instance, if the acceleration structure is implemented internally with bounding volumes, the implementation may find it beneficial to store relatively long triangles in multiple bounding boxes rather than a larger single box.

However, some application use cases require that intersections be reported to any hit shader at most once. This flag enables that guarantee for the given geometry, potentially with some performance impact.

This flag applies to all geometry types.

## Remarks

## See also