## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAGS** enumeration defines flags that indicate the type(s) of warped motion transformations that can be applied to reference frames in AV1 encoding.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_NONE`

No warped motion transformation types are supported, and therefore, the encoder will not use warped motion for reference frames.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_IDENTITY`

Indicates support for the identity transformation, where the reference frame is not transformed.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_TRANSLATION`

Indicates support for the translation transformation.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_ROTZOOM`

Indicates support for the rotation and zoom transformation.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_AFFINE`

Indicates support for the affine transformation.

## Remarks

If only **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAG_NONE** is supported, reference warp motion arguments are ignored and AV1 is_global syntax is false for all references.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_reference_warped_motion_transformation_0095)

[**D3D12DDI_VIDEO_ENCODER_CODEC_AV1_PICTURE_CONTROL_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_av1_picture_control_support_0095)