## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095** structure contains configuration support parameters for AV1 encoding.

## Members

### `SupportedFeatureFlags`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags) enumeration that indicates which features are supported for the codec. Supported features can be set or not by the API Client.

### `RequiredFeatureFlags`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags) enumeration that indicates which features the driver requires to be set by the API Client.

### `SupportedInterpolationFilters`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_interpolation_filters_0095_flags) enumeration that indicates which values can be selected as input parameters of type [**D3D12DDI_VIDEO_ENCODER_AV1_INTERPOLATION_FILTERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_interpolation_filters_0095).

### `SupportedRestorationParams[3]`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_support_0095_flags) enumeration that indicates which values can be selected as input parameters for **FrameRestorationType** and **LoopRestorationPixelSize** in [**D3D12DDI_VIDEO_ENCODER_AV1_RESTORATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_restoration_config_0095).

The first array indexing corresponds to the restoration filter type.

| Index i in SupportedRestorationParams[i][j] | Filter type |
|--------------------------------------------|-------------|
| 0 | SWITCHABLE |
| 1 | WIENER |
| 2 | SGRPROJ |

Note the indexing of the filter types corresponds to D3D12_VIDEO_ENCODER_AV1_RESTORATION_TYPE minus 1 (skipping D3D12_VIDEO_ENCODER_AV1_RESTORATION_TYPE_DISABLED).

The second array indexing corresponds to the planes.

| Index j in SupportedRestorationParams[i][j] | Plane |
| ------------------------------------------- | ----- |
| 0 | Y plane |
| 1 | U plane |
| 2 | V plane |

The value returned in SupportedRestorationParams[i][j] is a bitflag mask indicating whether the i-th filter in the j-th plane is either:

* Not supported indicated by SupportedRestorationParams[i][j] = D3D12_VIDEO_ENCODER_AV1_RESTORATION_SUPPORT_FLAG_NOT_SUPPORTED.
* Supported with any of the D3D12_VIDEO_ENCODER_AV1_RESTORATION_TILESIZE as indicated by the combinable bit flags in SupportedRestorationParams[i][j].

### `SupportedSegmentationModes`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_MODE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_mode_0095_flags) enumeration that indicates which segmentation modes can be selected in [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_CONFIG_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_config_0095).

### `SupportedTxModes[4]`

Output parameter. An array of [**D3D12DDI_VIDEO_ENCODER_AV1_TX_MODE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_tx_mode_0095_flags) values that indicates which transform mode values can be selected as input parameters of type [**D3D12DDI_VIDEO_ENCODER_AV1_TX_MODE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_tx_mode_0095) for each different [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_frame_type_0095). The driver must support at least 1 mode for each frame type; that is, the mask value can't be 0.

### `SegmentationBlockSize`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_SEGMENTATION_BLOCK_SIZE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_block_size_0095) enumeration that indicates the block size for the segment map. This is both for the input blocks in [**D3D12_VIDEO_ENCODER_AV1_SEGMENTATION_MAP_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_segmentation_map_0095) for custom segmentation or the block size of the segment map written in the compressed bitstream by the driver in auto segmentation.

### `PostEncodeValuesFlags`

A [**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095_flags) enumeration that specifies which AV1 encoding features the underlying encoder is able to override the associated AV1 syntax values for or accept API Client configurable input exactly.

### `MaxTemporalLayers`

Specifies the maximum number of temporal layers that can be supported. The reported values must be in the range [1..MaxTemporalIdSupported + 1]. A reported value 1, there is no temporal scalability support.

### `MaxSpatialLayers`

Specifies the maximum number of spatial layers that can be supported. The reported values must be in the range [1..MaxSpatialIdSupported + 1]. A reported value 1, there is no spatial scalability support.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDICAPS_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_DATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_codec_configuration_support_data_0083_0)