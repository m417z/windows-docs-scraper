# D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054 structure

## Description

Build inputs for the [PFND3D12DDI_GET_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_raytracing_acceleration_structure_prebuild_info_0054) callback function.

## Members

### `Type`

A [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_type) enumeration that specifies the type of ray tracing acceleration structure to build.

### `Flags`

A [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_build_flags) flag that specifies the build options.

### `NumDescs`

The acceleration structure update count.

### `DescsLayout`

A [D3D12DDI_ELEMENTS_LAYOUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_elements_layout) that defines the geometry ordering in a bottom-level acceleration structure.

### `InstanceDescs`

A D3D12DDI_GPU_VIRTUAL_ADDRESS that defines the instance order in a top-level acceleration structure.

### `pGeometryDescs`

Pointer to a [D3D12DDI_RAYTRACING_GEOMETRY_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_geometry_desc_0054) that defines the geometry description.

### `ppGeometryDescs`

Pointer to the D3D12DDI_RAYTRACING_GEOMETRY_DESC_0054 pointer.

## Remarks

## See also