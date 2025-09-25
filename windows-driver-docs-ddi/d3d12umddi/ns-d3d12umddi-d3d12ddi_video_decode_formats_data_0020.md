# D3D12DDI_VIDEO_DECODE_FORMATS_DATA_0020 structure

## Description

Specifies information used to retrieve a list of supported formats for a decode configuration.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `Configuration`

Specifies the decode configuration for the list of formats.

### `FormatCount`

The number of formats to retrieve. The runtime ensures this value matches the value returned from [PFND3D12DDI_VIDEO_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with D3D12DDI_CAPSTYPE_VIDEO set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILE_FORMAT_COUNT.

### `pOutputFormats`

A pointer to the returned supported formats. The calling application allocates storage for the format list.

## Remarks

These methods allow the list of supported decode formats supported by hardware. First, use PFND3D12DDDI_VIDEO_GETCAPS is called with D3D12DDICAPS_TYPE_VIDEO set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILE_FORMAT_COUNT to retrieve the number of supported formats. The caller uses this to allocate storage to retrieve the list of formats. The list is then retrieved through PFND3D12DDI_VIDEO_GETCAPS with the D3D12DDICAPS_TYPE set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILE_FORMATS.

## See also