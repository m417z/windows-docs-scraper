# D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER structure

## Description

Defines the header for a serialized raytracing acceleration structure.

## Members

### `DriverMatchingIdentifier`

The driver-matching identifier.

### `SerializedSizeInBytesIncludingHeader`

The size of serialized data.

### `DeserializedSizeInBytes`

Size of the memory that will be consumed when the acceleration structure is deserialized. This value is less than or equal to the size of the original acceleration structure before it was serialized.

### `NumBottomLevelAccelerationStructurePointersAfterHeader`

Size of the array of [D3D12_GPU_VIRTUAL_ADDRESS](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12_gpu_virtual_address) values that follow the header. For more information, see [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_raytracing_acceleration_structure_postbuild_info_serialization_desc).