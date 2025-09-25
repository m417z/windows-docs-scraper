# D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC structure

## Description

Describes the size and layout of the serialized acceleration structure and header

## Members

### `SerializedSizeInBytes`

The size of the serialized acceleration structure, including a header. The header is [D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_serialized_raytracing_acceleration_structure_header) followed by followed by a list of pointers to bottom-level acceleration structures.

### `NumBottomLevelAccelerationStructurePointers`

The number of 64-bit GPU virtual addresses that will be at the start of the serialized acceleration structure, after the [D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_serialized_raytracing_acceleration_structure_header). For a bottom-level acceleration structure this will be 0. For a top-level acceleration structure, the pointers indicate the acceleration structures being referred to.

When deserialization occurs, these pointers to bottom-level pointers must be initialized by the app in the serialized data (just after the header) to the new locations where the bottom level acceleration structures will reside. It is not required that these new locations to have already been populated with bottom-level acceleration structures at deserialization time, as long as they are initialized with the expected deserialized data structures before being used in raytracing. During deserialization, the driver reads the new pointers, using them to produce an equivalent top-level acceleration structure to the original.