# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC structure

## Description

Description of the post-build information to generate from an acceleration structure. Use this structure in calls to [EmitRaytracingAccelerationStructurePostbuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-emitraytracingaccelerationstructurepostbuildinfo) and [BuildRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-buildraytracingaccelerationstructure).

## Members

### `DestBuffer`

Storage for the post-build info result. Size required and the layout of the contents written by the system depend on the value of the *InfoType* field.

The memory pointed to must be in state [D3D12_RESOURCE_STATE_UNORDERED_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states). The memory must be aligned to the natural alignment for the members of the particular output structure being generated (e.g. 8 bytes for a struct with the largest members being UINT64).

### `InfoType`

A [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_type) value specifying the type of post-build information to retrieve.