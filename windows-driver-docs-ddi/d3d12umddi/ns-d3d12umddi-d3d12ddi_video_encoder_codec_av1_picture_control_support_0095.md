## Description

The **D3D12DDI_VIDEO_ENCODER_CODEC_AV1_PICTURE_CONTROL_SUPPORT_0095** structure describes the picture control support settings for the AV1 encoder.

## Members

### `PredictionMode`

Input parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_COMP_PREDICTION_TYPE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_comp_prediction_type_0095) enumeration that specifies the requested prediction mode to be used. The driver must return the output parameters assuming a frame will be encoded using this prediction mode in the picture params structure.

### `MaxUniqueReferencesPerFrame`

Output parameter. Indicates how many unique reference frames in the DPB can be selected at the same time for a given frame from any of the reference types (LAST, ..., ALTREF, etc) in the picture control parameters from the DPB that the API Client manages. In other words, the maximum number distinct (and with **ReconstructedPictureResourceIndex** != 0xFF) entries in [**D3D12DDI_VIDEO_ENCODE_REFERENCE_FRAMES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encode_reference_frames_0080)**.pSubresources**[ReferenceFramesReconPictureDescriptors[ReferenceIndices[i]].ReconstructedPictureResourceIndex] for i in [0..7].

### `SupportedFrameTypes`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_frame_type_0095_flags) enumeration that specifies the supported frame types to be used in [**D3D12DDI_VIDEO_ENCODER_AV1_FRAME_TYPE_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_frame_type_0095).

### `SupportedReferenceWarpedMotionFlags`

Output parameter. A [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_reference_warped_motion_transformation_0095_flags) enumeration that specifies the supported types to be used in [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_reference_picture_warped_motion_info_0095)**.TransformationType**.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_picture_control_support_0080_2)