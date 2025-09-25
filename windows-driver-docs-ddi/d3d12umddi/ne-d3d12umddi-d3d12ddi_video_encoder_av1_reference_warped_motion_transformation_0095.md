## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095** enumeration defines the types of warped motion transformations that can be applied to reference frames in AV1 encoding.

## Constants

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_IDENTITY:0`

Indicates the identity transformation. [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_reference_picture_warped_motion_info_0095) has zero parameters.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_TRANSLATION:1`

Indicates translational motion. **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095** has two parameters.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_ROTZOOM:2`

Indicates simplified affine with rotation and zoom. **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095** has four parameters.

### `D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_AFFINE:3`

Indicates affine transform. **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095** has six parameters.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_reference_warped_motion_transformation_0095_flags)

[**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_reference_picture_warped_motion_info_0095)