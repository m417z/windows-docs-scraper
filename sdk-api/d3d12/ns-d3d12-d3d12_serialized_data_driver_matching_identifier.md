# D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER structure

## Description

Opaque data structure describing driver versioning for a serialized acceleration structure. Pass this structure into a call to [ID3D12Device5::CheckDriverMatchingIdentifier](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device5-checkdrivermatchingidentifier) to determine if a previously serialized acceleration structure is compatible with the current driver/device, and can therefore be deserialized and used for raytracing.

## Members

### `DriverOpaqueGUID`

The opaque identifier of the driver.

### `DriverOpaqueVersioningData`

The opaque driver versioning data.