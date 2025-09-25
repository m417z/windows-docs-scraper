# ID3D12GraphicsCommandList4::CopyRaytracingAccelerationStructure

## Description

Copies a source acceleration structure to destination memory while applying the specified transformation.

## Parameters

### `DestAccelerationStructureData` [in]

The destination memory. The required size can be discovered by calling [EmitRaytracingAccelerationStructurePostbuildInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-emitraytracingaccelerationstructurepostbuildinfo) beforehand, if necessary for the specified *Mode*.

The destination start address must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), regardless of the specified *Mode*.

The destination memory range cannot overlap source. Otherwise, results are undefined.

The resource state that the memory pointed to must be in depends on the *Mode* parameter. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_copy_mode).

### `SourceAccelerationStructureData` [in]

The address of the acceleration structure or other type of data to copy/transform based on the specified *Mode*. The data remains unchanged and usable. The operation only copies the data pointed to by *SourceAccelerationStructureData* and not any other data, such as acceleration structures, that the source data may point to. For example, in the case of a top-level acceleration structure, any bottom-level acceleration structures that it points to are not copied in the operation.

The source memory must be aligned to 256 bytes, defined as [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT](https://learn.microsoft.com/windows/desktop/direct3d12/constants), regardless of the specified *Mode*.

The resource state that the memory pointed to must be in depends on the *Mode* parameter. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_copy_mode).

### `Mode` [in]

The type of copy operation to perform. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_copy_mode).

## Remarks

Since raytracing acceleration structures may contain internal pointers and have a device dependent opaque layout, copying them around or otherwise manipulating them requires a dedicated API so that drivers can handle the requested operation.

This method can be called from graphics or compute command lists but not from bundles.

## See also

[ID3D12GraphicsCommandList4](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12graphicscommandlist4)