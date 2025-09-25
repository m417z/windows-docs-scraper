# D3D12_RAYTRACING_GEOMETRY_TYPE enumeration

## Description

Specifies the type of geometry used for raytracing. Use a value from this enumeration to specify the geometry type in a [D3D12_RAYTRACING_GEOMETRY_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_desc).

## Constants

### `D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES:0`

The geometry consists of triangles.

### `D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS`

The geometry procedurally is defined during raytracing by intersection shaders. For the purpose of acceleration structure builds, the geometry’s bounds are described with axis-aligned bounding boxes using the [D3D12_RAYTRACING_GEOMETRY_AABBS_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_aabbs_desc) structure.