## Description

Emits post-build properties for a set of acceleration structures. This enables applications to know the output resource requirements for performing acceleration structure operations via [ID3D12GraphicsCommandList4::CopyRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-copyraytracingaccelerationstructure).

## Parameters

### `pDesc` [in]

A [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_desc) object describing post-build information to generate.

### `NumSourceAccelerationStructures` [in]

Number of pointers to acceleration structure GPU virtual addresses pointed to by *pSourceAccelerationStructureData*. This number also affects the destination (output), which will be a contiguous array of **NumSourceAccelerationStructures** output structures, where the type of the structures depends on *InfoType* field of the supplied in the *pDesc* description.

### `pSourceAccelerationStructureData` [in]

Pointer to array of GPU virtual addresses of size *NumSourceAccelerationStructures*.

The address must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants).

The memory pointed to must be in state [D3D12_RESOURCE_STATE_RAYTRACING_ACCELERATION_STRUCTURE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

## Remarks

This method can be called from graphics or compute command lists but not from bundles.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)