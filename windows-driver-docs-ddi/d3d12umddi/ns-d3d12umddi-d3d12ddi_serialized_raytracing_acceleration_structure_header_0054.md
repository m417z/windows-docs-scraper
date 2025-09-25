# D3D12DDI_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER_0054 structure

## Description

Describes the header for a serialized ray tracing acceleration structure.

## Members

### `DriverMatchingIdentifier`

A [D3D12DDI_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER_0054](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_serialized_data_driver_matching_identifier_0054) structure.

### `SerializedSizeInBytesIncludingHeader`

Size of the serialized acceleration structure, including a header.

### `DeserializedSizeInBytes`

Size of the deserialized acceleration structure, in bytes.

### `NumBottomLevelAccelerationStructurePointersAfterHeader`

A 64-byte number of bottom-level acceleration structure pointers.

## Remarks

## See also