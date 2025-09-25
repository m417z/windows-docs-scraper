## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAGS** enumeration specifies flags for the AV1-specific picture control properties.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_NONE:0x0`

No flags.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_ERROR_RESILIENT_MODE:0x1`

Related to error_resilient_mode AV1 syntax in frame header.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_DISABLE_CDF_UPDATE:0x2`

Related to AV1 syntax for disable_cdf_update.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_PALETTE_ENCODING:0x4`

Enables the usage of palette encoding for this frame.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_SKIP_MODE:0x8`

Related to AV1 syntax skip_mode_present. skip_mode element will be present for this frame if this flag is set. Please check support in AV1 query caps before enabling this feature.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_FRAME_REFERENCE_MOTION_VECTORS:0x10`

Related to AV1 syntax use_ref_frame_mvs. Equal to 1 specifies that motion vector information from a previous frame can be used when encoding the current frame. use_ref_frame_mvs equal to 0 specifies that this information will not be used.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_FORCE_INTEGER_MOTION_VECTORS:0x20`

Equal to 1 specifies that force_integer_mv may be enabled on a per frame basis. Equal to 0 specifies that force_integer_mv syntax element will not be used. Please check support in AV1 query caps before enabling this feature.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ALLOW_INTRA_BLOCK_COPY:0x40`

Indicates if intra block copy is supported or not at per frame basis. Related to allow_intrabc syntax in AV1 spec.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_USE_SUPER_RESOLUTION:0x80`

Related to AV1 syntax use_superres.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_DISABLE_FRAME_END_UPDATE_CDF:0x100`

Related to AV1 syntax disable_frame_end_update_cdf.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_FRAME_SEGMENTATION_AUTO:0x200`

Enables automatic (performed by driver without API Client input) segmentation for the current frame. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_AUTO_SEGMENTATION. This flag must not be combined with D3D12_VIDEO_ENCODER_AV1_PICTURE_CONTROL_FLAG_ENABLE_FRAME_SEGMENTATION_CUSTOM.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_FRAME_SEGMENTATION_CUSTOM:0x400`

Enables customized segmentation with the API Client sending the driver segmentation config and segment map. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_CUSTOM_SEGMENTATION. This flag must not be combined with D3D12_VIDEO_ENCODER_AV1_PICTURE_CONTROL_FLAG_ENABLE_FRAME_SEGMENTATION_AUTO.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_WARPED_MOTION:0x800`

Related to AV1 syntax allow_warped_motion to be coded in the frame header. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_WARPED_MOTION.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_REDUCED_TX_SET:0x1000`

Related to AV1 syntax reduced_tx_set. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_REDUCED_TX_SET.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_MOTION_MODE_SWITCHABLE:0x2000`

Related to AV1 syntax is_motion_mode_switchable. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_MOTION_MODE_SWITCHABLE.

### `D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ALLOW_HIGH_PRECISION_MV:0x4000`

Related to AV1 syntax allow_high_precision_mv. Requires D3D12_VIDEO_ENCODER_AV1_FEATURE_FLAG_ALLOW_HIGH_PRECISION_MV.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)