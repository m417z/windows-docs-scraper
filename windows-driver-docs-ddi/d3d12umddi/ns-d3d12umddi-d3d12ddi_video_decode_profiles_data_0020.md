# D3D12DDI_VIDEO_DECODE_PROFILES_DATA_0020 structure

## Description

Specifies information used to retrieve a list of profiles.

## Members

### `NodeIndex`

In multi-adapter operation, this indicates which physical adapter of the device this operation applies to.

### `ProfileCount`

The number of profiles to retrieve. The runtime ensures this value matches the value returned from [PFND3D12DDI_VIDEO_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_getcaps) with D3D12DDI_CAPSTYPE_VIDEO set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILE_COUNT.

### `pProfiles`

A pointer to the returned supported profiles. The calling application allocates storage for the profile list.

## Remarks

These capabilities allow the list of supported decode profiles supported by hardware. First, use PFND3D12DDDI_VIDEO_GETCAPS called with D3D12DDICAPS_TYPE_VIDEO set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILE_COUNT to retrieve the number of supported profiles. The caller uses this to allocate storage to retrieve the list of profiles. Then, the list is retrieved through PFND3D12DDI_VIDEO_GETCAPS with the D3D12DDICAPS_TYPE set to D3D12DDICAPS_TYPE_VIDEO_DECODE_PROFILES.