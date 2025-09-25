# D3D12_RAYTRACING_GEOMETRY_FLAGS enumeration

## Description

Specifies flags for raytracing geometry in a [D3D12_RAYTRACING_GEOMETRY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_desc) structure.

## Constants

### `D3D12_RAYTRACING_GEOMETRY_FLAG_NONE:0`

No options specified.

### `D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE:0x1`

When rays encounter this geometry, the geometry acts as if no any hit shader is present. It is recommended that apps use this flag liberally, as it can enable important ray-processing optimizations. Note that this behavior can be overridden on a per-instance basis with [D3D12_RAYTRACING_INSTANCE_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_instance_flags) and on a per-ray basis using ray flags in **TraceRay**.

### `D3D12_RAYTRACING_GEOMETRY_FLAG_NO_DUPLICATE_ANYHIT_INVOCATION:0x2`

By default, the system is free to trigger an any hit shader more than once for a given ray-primitive intersection. This flexibility helps improve the traversal efficiency of acceleration structures in certain cases. For instance, if the acceleration structure is implemented internally with bounding volumes, the implementation may find it beneficial to store relatively long triangles in multiple bounding boxes rather than a larger single box. However, some application use cases require that intersections be reported to the any hit shader at most once. This flag enables that guarantee for the given geometry, potentially with some performance impact.

This flag applies to all geometry types.