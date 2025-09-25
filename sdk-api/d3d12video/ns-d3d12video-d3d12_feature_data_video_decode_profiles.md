# D3D12_FEATURE_DATA_VIDEO_DECODE_PROFILES structure

## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_PROFILES](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of supported profiles.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `ProfileCount`

The number of profiles to retrieve. This number must match the value returned from a call [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12\_FEATURE\_VIDEO\_DECODE\_PROFILE\_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video).

### `pProfiles`

A list of GUIDs representing the supported profiles. The calling application must allocate storage for the profile list before calling **CheckFeatureSupport**.

## Remarks

## See also

[D3D12_FEATURE_VIDEO_DECODE_CONVERSION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video)