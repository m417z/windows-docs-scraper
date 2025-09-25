# D3D12DDI_RAYTRACING_GEOMETRY_DESC_0054 structure

## Description

Describes a ray tracing geometry.

## Members

### `Type`

A [D3D12DDI_RAYTRACING_GEOMETRY_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_geometry_type) type.

### `Flags`

A [D3D12DDI_RAYTRACING_GEOMETRY_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_geometry_flags) flag.

### `Triangles`

A [D3D12DDI_RAYTRACING_GEOMETRY_TRIANGLES_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_geometry_triangles_desc_0054) structure that describes a triangle geometry if *Type* is D3D12DDI_RAYTRACING_GEOMETRY_TYPE_TRIANGLES. Otherwise, this parameter is unused.

### `AABBs`

A [D3D12DDI_RAYTRACING_GEOMETRY_AABBS_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_geometry_aabbs_desc_0054) structure that describes an AABB (axis-aligned bounding box) geometry if *Type* is D3D12DDI_RAYTRACING_GEOMETRY_TYPE_PROCEDURAL_PRIMITIVE_AABBS. Otherwise, this parameter is unused.

## Remarks

## See also