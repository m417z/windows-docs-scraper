# ID3D12Device5::CheckDriverMatchingIdentifier

## Description

Reports the compatibility of serialized data, such as a serialized raytracing acceleration structure resulting from a call to [CopyRaytracingAccelerationStructure](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist4-copyraytracingaccelerationstructure) with mode [D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE_SERIALIZE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_raytracing_acceleration_structure_copy_mode), with the current device/driver.

## Parameters

### `SerializedDataType` [in]

The type of the serialized data. For more information, see [D3D12_SERIALIZED_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_serialized_data_type).

### `pIdentifierToCheck` [in]

Identifier from the header of the serialized data to check with the driver. For more information, see [D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_serialized_data_driver_matching_identifier).

## Return value

The returned compatibility status. For more information, see [D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_driver_matching_identifier_status).

## See also

[ID3D12Device5](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device5)