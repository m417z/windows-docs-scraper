# D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC structure

## Description

Describes a raytracing acceleration structure. Pass this structure into [ID3D12GraphicsCommandList4::BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure) to describe the acceleration structure to be built.

## Members

### `DestAccelerationStructureData`

Location to store resulting acceleration structure. [ID3D12Device5::GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-getraytracingaccelerationstructureprebuildinfo) reports the amount of memory required for the result here given a set of acceleration structure build parameters.

The address must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

> [!IMPORTANT]
> The memory must be in state [**D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

### `Inputs`

Description of the input data for the acceleration structure build. This is data is stored in a separate structure because it is also used with **GetRaytracingAccelerationStructurePrebuildInfo**.

### `SourceAccelerationStructureData`

Address of an existing acceleration structure if an acceleration structure update (an incremental build) is being requested, by setting [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_build_flags) in the Flags parameter. Otherwise this address must be NULL.

If this address is the same as *DestAccelerationStructureData*, the update is to be performed in-place. Any other form of overlap of the source and destination memory is invalid and produces undefined behavior.

The address must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), which should automatically be the case because any existing acceleration structure passed in here would have already been required to be placed with such alignment.

> [!IMPORTANT]
> The memory must be in state [**D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

#### ScratchAccelerationStructureData

Location where the build will store temporary data. **GetRaytracingAccelerationStructurePrebuildInfo** reports the amount of scratch memory the implementation will need for a given set of acceleration structure build parameters.

> [!IMPORTANT]
> The memory must be in state [**D3D12_RESOURCE_STATE_UNORDERED_ACCESS**](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

### `ScratchAccelerationStructureData`