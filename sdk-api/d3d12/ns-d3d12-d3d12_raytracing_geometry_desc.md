# D3D12_RAYTRACING_GEOMETRY_DESC structure

## Description

Describes a set of geometry that is used in the [D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_build_raytracing_acceleration_structure_inputs) structure to provide input data to a raytracing acceleration structure build operation.

## Members

### `Type`

The type of geometry.

### `Flags`

The geometry flags

### `Triangles`

A [D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_triangles_desc) describing triangle geometry, if *Type* is [D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_geometry_type). Otherwise this parameter is unused.

### `AABBs`

A [D3D12_RAYTRACING_GEOMETRY_AABBS_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_geometry_aabbs_desc) describing triangle geometry, if *Type* is [D3D12_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_geometry_type). Otherwise this parameter is unused.