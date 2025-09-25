## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_0082_0** structure describes the picture-level control elements for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command for HEVC encoding.

## Members

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_HEVC_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_hevc_flags_0082_0) value that specifies the configuration flags for this frame that is to be encoded. Flags can be combined.

### `FrameType`

A [**D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_HEVC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_type_hevc_0080) value that sets the picture type. Check that the codec-specific flags support the type before selecting a value.

> [!NOTE]
>
> **FrameType** must be kept in sync with the group of pictures (GOP) structure configuration set by the host. The GOP is defined in *display order*. The picture type selection must follow the GOP but in encode order.

### `slice_pic_parameter_set_id`

Value to be used in the slice headers of the current frame to reference the picture parameter set (PPS).

### `PictureOrderCountNumber`

Current frame display order.

### `TemporalLayerIndex`

The picture layer number in temporal hierarchy. Check [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0) for the maximum number of layers.

### `List0ReferenceFramesCount`

The number of past frame references to be used for this frame. This value should be coherent with what was exposed in [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0).

### `pList0ReferenceFrames`

Pointer to the list of past frame reference frames to be used for this frame. Each integer value in this array indexes into **pReferenceFramesReconPictureDescriptors** to reference pictures kept in the decoded picture buffer (DPB).

### `List1ReferenceFramesCount`

The number of future frame references to be used for this frame. This value should be coherent with what was exposed in [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_HEVC_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_hevc_0083_0).

### `pList1ReferenceFrames`

Pointer to the list of future frame reference frames to be used for this frame. Each integer value in this array indexes into **pReferenceFramesReconPictureDescriptors** to reference pictures kept in the DPB.

### `ReferenceFramesReconPictureDescriptorsCount`

The number of entries in **pReferenceFramesReconPictureDescriptors**.

### `pReferenceFramesReconPictureDescriptors`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_HEVC_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_reference_picture_descriptor_hevc_0082_0) structure that describes the current state of the DPB buffer kept in [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0). The L0/L1 lists indices map from past/future references into this descriptors array.

In turn, this array of descriptors maps a reference picture for this frame into a resource index in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) reconstructed pictures array. Additionally, for each reference picture it indicates the encode and display order number and whether it is a long term reference.

The size of this array matches [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames.NumTextures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command.

### `List0RefPicModificationsCount`

The number of list modifications for the L0 list.

### `pList0RefPicModifications`

Pointer to a list that contains **List0RefPicModificationsCount** modification commands for the L0 list.

### `List1RefPicModificationsCount`

The number of list modifications for the L1 list.

### `pList1RefPicModifications`

Pointer to a list that contains **List1RefPicModificationsCount** modification commands for the L1 list.

### `QPMapValuesCount`

The number of elements present in the array that **pRateControlQPMap** points to. This value should match the number of coding blocks in the frame, rounding up the frame resolution to the closest aligned values.

### `pRateControlQPMap`

Pointer to an array that contains, in row/column scan order, the quantization parameter (QP) map values to use on each squared region for this frame. The QP map dimensions can be calculated using the current resolution and [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2.QPMapRegionPixelsSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) conveying the squared region sizes.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0)