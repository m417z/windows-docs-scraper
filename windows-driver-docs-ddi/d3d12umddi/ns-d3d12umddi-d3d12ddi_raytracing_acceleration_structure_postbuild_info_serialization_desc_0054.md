# D3D12DDI_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC_0054 structure

## Description

Space requirements for serializing a ray tracing acceleration structure used by tools.

## Members

### `SerializedSizeInBytes`

Size of the serialized acceleration structure, including a [D3D12DDI_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_serialized_raytracing_acceleration_structure_header_0054) header.

### `NumBottomLevelAccelerationStructurePointers`

Specifies how many 64-bit GPUVAs (graphical processing unit virtual address) will be at the start of the serialized acceleration structure. For a bottom-level acceleration structure this will be 0. For a top-level acceleration structure, the pointers indicate the acceleration structures being referred to. When deserializing happens, these pointers must be initialized by the app in the serialized data, just after the header, to the new locations of the equivalent acceleration structures. These new locations pointed to at deserialize time need not have been populated with bottom level acceleration structures yet, as long as they have been initialized with the expected deserialized data structures before use in raytracing. During deserialization, the driver reads the new pointers, using them to produce an equivalent top-level acceleration structure to the original.

## Remarks

## See also