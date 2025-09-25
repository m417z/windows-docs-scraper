## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0** structure describes the picture-level control elements for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command for H.264 encoding.

## Members

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_flags_0080) value that specifies the configuration flags for this frame that is to be encoded. Flags can be combined.

### `FrameType`

A [**D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_type_h264_0080) value that sets the picture type. Check that the codec-specific flags support the type before selecting a value.

> [!NOTE]
>
> **FrameType** must be kept in sync with the group of pictures (GOP) structure configuration set by the host. The GOP is defined in *display order*. The picture type selection must follow the GOP but in encode order.

### `pic_parameter_set_id`

Value used in the slice headers of the current frame to reference the picture parameter set (PPS).

### `idr_pic_id`

When the frame is of type [**D3D12DDI_VIDEO_ENCODER_FRAME_TYPE_H264_0080_IDR_FRAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_type_h264_0080), **idr_pic_id** identifies the Instantaneous Decoder Refresh (IDR) frame to be used in all the slices headers present in the frame.

### `PictureOrderCountNumber`

The current frame display order.

### `FrameDecodingOrderNumber`

The frame *decode* order with semantics indicated by the slice header *frame_num* element that increments after each reference picture.

### `TemporalLayerIndex`

The picture layer number in temporal hierarchy. Check [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0) for the maximum number of layers.

### `List0ReferenceFramesCount`

The number of past frame references to be used for this frame. This value should be coherent with what was exposed in [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0).

### `pList0ReferenceFrames`

Pointer to the list of past frame reference frames to be used for this frame. Each integer value in this array indexes into **pReferenceFramesReconPictureDescriptors** to reference pictures kept in the decoded picture buffer (DPB).

### `List1ReferenceFramesCount`

The number of future frame references to be used for this frame. This value should be coherent with what was exposed in [**D3D12DDI_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_codec_configuration_support_h264_0082_0).

### `pList1ReferenceFrames`

Pointer to the list of future frame reference frames to be used for this frame. Each integer value in this array indexes into **pReferenceFramesReconPictureDescriptors** to reference pictures kept in the DPB.

### `ReferenceFramesReconPictureDescriptorsCount`

The number of entries in **pReferenceFramesReconPictureDescriptors**.

### `pReferenceFramesReconPictureDescriptors`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_REFERENCE_PICTURE_DESCRIPTOR_H264_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_reference_picture_descriptor_h264_0080) structure that describes the current state of the DPB buffer kept in [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0). The L0/L1 lists indices map from past/future references into this descriptors array.

In turn, this array of descriptors maps a reference picture for this frame into a resource index in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) reconstructed pictures array. Additionally, for each reference picture it indicates the encode and display order number and whether it is a long term reference.

The size of this array matches [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0.ReferenceFrames.NumTextures**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_desc_0082_0) for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command.

### `adaptive_ref_pic_marking_mode_flag`

Defines a semantic mode for the frame reference handling. This flag can be one of the following values.

| Value | Reference picture marking mode |
| ----- | ------------------------------ |
| 0 | Sliding window reference picture marking mode: A marking mode providing a first-in first-out mechanism for short-term reference pictures. |
| 1 | Adaptive reference picture marking mode: A reference picture marking mode providing syntax elements to specify marking of reference pictures as "unused for reference" and to assign long-term frame indices. |

### `RefPicMarkingOperationsCommandsCount`

Number of reference pictures marking operations associated with the current frame. This member requires that **adaptive_ref_pic_marking_mode_flag** be set to 1.

### `pRefPicMarkingOperationsCommands`

Pointer to [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_MARKING_OPERATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_reference_picture_marking_operation_0082_0) structure that contains a list of **RefPicMarkingOperationsCommandsCount** reference pictures marking operations associated with the current frame. This member requires that **adaptive_ref_pic_marking_mode_flag** be set to 1.

The operations described by this list must be reflected in the DPB descriptors accordingly during the encoding session.

### `List0RefPicModificationsCount`

The number of list modifications for the L0 list.

### `pList0RefPicModifications`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_LIST_MODIFICATION_OPERATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_reference_picture_list_modification_operation_0082_0) structure that contains **List0RefPicModificationsCount** modification commands for the L0 list.

### `List1RefPicModificationsCount`

The number of list modifications for the L1 list.

### `pList1RefPicModifications`

Pointer to a [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_LIST_MODIFICATION_OPERATION_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_reference_picture_list_modification_operation_0082_0) structure that contains **List1RefPicModificationsCount** modification commands for the L1 list.

### `QPMapValuesCount`

The number of elements present in the array that **pRateControlQPMap** points to. This value should match the number of coding blocks in the frame, rounding up the frame resolution to the closest aligned values.

### `pRateControlQPMap`

Pointer to an array that contains, in row/column scan order, the quantization parameter (QP) map values to use on each squared region for this frame. The QP map dimensions can be calculated using the current resolution and [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2.QPMapRegionPixelsSize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2) conveying the squared region sizes.

## Remarks

If the current frame is marked as a reference picture, the output must contain the reconstructed picture along with the bitstream for the host to place it in future commands in the reconstructed pictures reference list. Note that there might be limitations for some frame types to be marked as references, so check feature support before setting those values.

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0)