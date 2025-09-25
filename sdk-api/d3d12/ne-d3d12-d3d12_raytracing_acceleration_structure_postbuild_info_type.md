# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE enumeration

## Description

Specifies the type of acceleration structure post-build info that can be retrieved with calls to [EmitRaytracingAccelerationStructurePostbuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-emitraytracingaccelerationstructurepostbuildinfo) and [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure).

## Constants

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE:0`

The post-build info is space requirements for an acceleration structure after compaction. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_compacted_size_desc).

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION:0x1`

The post-build info is space requirements for generating tools visualization for an acceleration structure. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_tools_visualization_desc).

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION:0x2`

The post-build info is space requirements for serializing an acceleration structure. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_serialization_desc).

### `D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE:0x3`

The post-build info is size of the current acceleration structure. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_current_size_desc).