# D3D12DDIARG_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_0054 structure

## Description

Description of the acceleration structure to build.

## Members

### `DestAccelerationStructureData`

Location to store the resulting acceleration structure from [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_build_raytracing_acceleration_structure_0054). [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_raytracing_acceleration_structure_prebuild_info_0054) reports the amount of memory required for the result here, given a set of acceleration structure build parameters.

The start address must be aligned to 256 bytes.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE.

### `Inputs`

A [D3D12DDI_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_build_raytracing_acceleration_structure_inputs_0054) structure that represents the ray tracing acceleration build inputs.

### `SourceAccelerationStructureData`

Address of an existing acceleration structure if an acceleration structure update like an incremental build is being requested, by setting D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PERFORM_UPDATE in the [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_build_flags) enumeration. Otherwise, this address must be NULL.

If this address is the same as *DestAccelerationStructureData*, the update is to be performed in-place. Any other form of overlap of the source and destination memory is invalid and produces undefined behavior.

The address must be aligned to 256 bytes.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE.

### `ScratchAccelerationStructureData`

Location where the build will store temporary data. [GetRaytracingAccelerationStructurePrebuildInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_get_raytracing_acceleration_structure_prebuild_info_0054) reports the amount of scratch memory the implementation will need for a given set of acceleration structure build parameters.

The start address must be aligned to 256 bytes. Contents of this memory going into a build on the GPU timeline are irrelevant and will not be preserved. After the build is complete on the GPU timeline, the memory is left with whatever undefined contents the build finished with.

The memory pointed to must be in [resource state](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_resource_states) D3D12DDI_RESOURCE_STATE_UNORDERED_ACCESS.

### `NumPostbuildInfoDescs`

The number of contiguous [D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_raytracing_acceleration_structure_postbuild_info_desc_0054) structures.

### `pPostbuildInfoDescs`

Points to an array of *NumPostbuildInfoDescs* pointers to D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC_0054 structures.

## Remarks

## See also