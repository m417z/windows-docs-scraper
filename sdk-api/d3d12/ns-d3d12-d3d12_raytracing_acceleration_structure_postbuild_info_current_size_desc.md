# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC structure

## Description

Describes the space currently used by an acceleration structure..

## Members

### `CurrentSizeInBytes`

Space currently used by an acceleration structure. If the acceleration structure hasn’t had a compaction operation performed on it, this size is the same one reported by [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo), and if it has been compacted this size is the same reported for post-build info with [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_type).

## Remarks

The information in this structure is useful for tools to be able to determine how much memory is occupied by an arbitrary acceleration structure currently sitting in memory.