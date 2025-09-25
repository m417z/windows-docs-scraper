# D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS enumeration

## Description

Specifies the result of a call to [ID3D12Device5::CheckDriverMatchingIdentifier](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-checkdrivermatchingidentifier) which queries whether serialized data is compatible with the current device and driver version.

## Constants

### `D3D12_DRIVER_MATCHING_IDENTIFIER_COMPATIBLE_WITH_DEVICE:0`

Serialized data is compatible with the current device/driver.

### `D3D12_DRIVER_MATCHING_IDENTIFIER_UNSUPPORTED_TYPE:0x1`

The specified [D3D12_SERIALIZED_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_serialized_data_type) specified is unknown or unsupported.

### `D3D12_DRIVER_MATCHING_IDENTIFIER_UNRECOGNIZED:0x2`

Format of the data in [D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_serialized_data_driver_matching_identifier) is unrecognized. This could indicate either corrupt data or the identifier was produced by a different hardware vendor.

### `D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_VERSION:0x3`

Serialized data is recognized, but its version is not compatible with the current driver. This result may indicate that the device is from the same hardware vendor but is an incompatible version.

### `D3D12_DRIVER_MATCHING_IDENTIFIER_INCOMPATIBLE_TYPE:0x4`

[D3D12_SERIALIZED_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_serialized_data_type) specifies a data type that is not compatible with the type of serialized data. As long as there is only a single defined serialized data type this error cannot not be produced.