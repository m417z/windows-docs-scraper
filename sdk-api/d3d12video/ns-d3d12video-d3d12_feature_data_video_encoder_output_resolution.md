## Description

Provides data for calls to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) when the feature specified is [D3D12_FEATURE_VIDEO_ENCODER_OUTPUT_RESOLUTION](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_feature_video). Retrieves the list of supported resolutions for the specified codec.

## Members

### `NodeIndex`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set a bit to identify the node (the device's physical adapter) to which the command queue applies. Each bit in the mask corresponds to a single node. Only 1 bit may be set.

### `Codec`

A member of the [D3D12_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_codec) enumeration specifying the codec for which the supported resolutions are being queried.

### `ResolutionRatiosCount`

The number of resolution ratios to retrieve. This number must match the number in the [D3D12_FEATURE_DATA_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT.ResolutionRatiosCount](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_output_resolution_ratios_count) field returned from a call to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport) with **D3D12_FEATURE_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT** specified as the feature.

### `IsSupported`

Receives a boolean indicating if the query inputs are supported.

### `MinResolutionSupported`

Receives the minimum resolution supported for the specified codec.

### `MaxResolutionSupported`

Receives the maximum resolution supported for the specified codec.

### `ResolutionWidthMultipleRequirement`

A UINT specifying a number by which the resolution width component must be divisible.

### `ResolutionHeightMultipleRequirement`

A UINT specifying a number by which the resolution height component must be divisible.

### `pResolutionRatios`

Receives a list of [D3D12_VIDEO_ENCODER_PICTURE_RESOLUTION_RATIO_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_resolution_desc) representing the supported resolution ratios for the specified codec as irreducible fractions. The caller must allocate the memory for this array based on the **ResolutionRatiosCount** field, and assign it to the query struct the call to ID3D12VideoDevice::CheckFeatureSupport.

## Remarks

## See also