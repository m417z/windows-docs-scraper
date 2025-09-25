# D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER_0054 structure

## Description

Describes the GPU memory layout of an acceleration structure visualization.

## Members

### `Type`

A [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_type) enumeration.

### `NumDescs`

The number of either [D3D12DDI_RAYTRACING_INSTANCE_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_instance_desc_0054) InstanceDescs[**NumDescs**] or [D3D12DDI_RAYTRACING_GEOMETRY_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_geometry_desc_0054) GeometryDescs[**NumDescs**], depending on the value of *Type*.

## Remarks

## See also