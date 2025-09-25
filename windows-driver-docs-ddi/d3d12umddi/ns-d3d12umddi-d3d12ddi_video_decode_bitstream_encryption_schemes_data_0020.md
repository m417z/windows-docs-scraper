# D3D12DDI_VIDEO_DECODE_BITSTREAM_ENCRYPTION_SCHEMES_DATA_0020 structure

## Description

Specifies information used to retrieve the bitstream encryption schemes supported for a decode profile.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `DecodeProfile`

The decode profile to retrieve bitstream encryption schemes for.

### `EncryptionSchemeCount`

The number of schemes to retrieve. The runtime ensures this value matches the value returned from PFND3D12DDI_VIDEO_GETCAPS with D3D12DDI_CAPSTYPE_VIDEO set to D3D12DDICAPS_TYPE_VIDEO_DECODE_BITSTREAM_ENCRYPTION_SCHEME_COUNT.

### `pEncryptionSchemes`

A pointer to a list of supported encryption schemes. The calling application allocates storage for the list before it calls the [CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport) method.

## See also

[CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-checkfeaturesupport)