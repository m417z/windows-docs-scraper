## Description

The **D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_WARPED_MOTION_INFO_0095** structure defines the information necessary to apply a warped motion transformation to a reference picture in AV1 encoding.

## Members

### `TransformationType`

A [**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_WARPED_MOTION_TRANSFORMATION_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_reference_warped_motion_transformation_0095) enumeration value that specifies the type of warped motion transformation to apply.

### `TransformationMatrix[8]`

This array consists of integers that represent the parameters of the transformation matrix for the warped motion. The exact usage of these parameters depends on the **TransformationType**.

### `InvalidAffineSet`

## Remarks

This structure is related to warped motion transformation/global motion type. It indicates the transform(s) to be applied to motion vectors.

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_REFERENCE_PICTURE_DESCRIPTOR_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_reference_picture_descriptor_0095)