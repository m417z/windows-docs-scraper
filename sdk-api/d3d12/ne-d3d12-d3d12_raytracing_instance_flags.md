# D3D12_RAYTRACING_INSTANCE_FLAGS enumeration

## Description

Flags for a raytracing acceleration structure instance. These flags can be used to override [D3D12_RAYTRACING_GEOMETRY_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_geometry_flags) for individual instances.

## Constants

### `D3D12_RAYTRACING_INSTANCE_FLAG_NONE:0`

No options specified.

### `D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_CULL_DISABLE:0x1`

Disables front/back face culling for this instance. The Ray flags **RAY_FLAG_CULL_BACK_FACING_TRIANGLES** and **RAY_FLAG_CULL_FRONT_FACING_TRIANGLES** will have no effect on this instance.

### `D3D12_RAYTRACING_INSTANCE_FLAG_TRIANGLE_FRONT_COUNTERCLOCKWISE:0x2`

This flag reverses front and back facings, which is useful if the application’s natural winding order differs from the default. By default, a triangle is front facing if its vertices appear clockwise from the ray origin and back facing if its vertices appear counter-clockwise from the ray origin, in object space in a left-handed coordinate system.

Since these winding direction rules are defined in object space, they are unaffected by instance transforms. For example, an instance transform matrix with negative determinant (e.g. mirroring some geometry) does not change the facing of the triangles within the instance. Per-geometry transforms defined in [D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_triangles_desc) , by contrast, get combined with the associated vertex data in object space, so a negative determinant matrix there does flip triangle winding.

### `D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE:0x4`

The instance will act as if [D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_geometry_flags) had been specified for all the geometries in the bottom-level acceleration structure referenced by the instance. Note that this behavior can be overridden by the ray flag **RAY_FLAG_FORCE_NON_OPAQUE**.

This flag is mutually exclusive to the **D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE** flag.

### `D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_NON_OPAQUE:0x8`

The instance will act as if [D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_geometry_flags) had not been specified for any of the geometries in the bottom-level acceleration structure referenced by the instance. Note that this behavior can be overridden by the ray flag **RAY_FLAG_FORCE_OPAQUE**.

This flag is mutually exclusive to the **D3D12_RAYTRACING_INSTANCE_FLAG_FORCE_OPAQUE** flag.