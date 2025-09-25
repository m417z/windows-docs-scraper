## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_MARKING_OPERATION_0082_0** structure describes changes in the reference pictures as memory operations as a tuple of an operation identifier and associated parameters needed for the operation.

## Members

### `memory_management_control_operation`

The control operation to be applied to affect the reference picture marking state. Valid operation values follow.

| Value | Description |
| ----- | ----------- |
| 0 | End memory_management_control_operation syntax element loop. |
| 1 | Mark a short-term reference picture as "unused for reference". |
| 2 | Mark a long-term reference picture as "unused for reference". |
| 3 | Mark a short-term reference picture as "used for long-term reference" and assign a long-term frame index to it. |
| 4 | Specify the maximum long-term frame index and mark all long-term reference pictures having long-term frame indices greater than the maximum value as "unused for reference". |
| 5 | Mark all reference pictures as "unused for reference" and set the *MaxLongTermFrameIdx* variable to "no long-term frame indices". |
| 6 | Mark the current picture as "used for long-term reference" and assign a long-term frame index to it. |

### `difference_of_pic_nums_minus1`

This member is used with **memory_management_control_operation** equal to 3 or 1 to assign a long-term frame index to a short-term reference picture or to mark a short-term reference picture as "unused for reference". When the associated **memory_management_control_operation** is processed by the decoding process, the resulting picture number derived from **difference_of_pic_nums_minus1** shall be a picture number assigned to one of the reference pictures marked as "used for reference" and not previously assigned to a long-term frame index.

### `long_term_pic_num`

This member is used with **memory_management_control_operation** equal to 2 to mark a long-term reference picture as "unused for reference". When the associated **memory_management_control_operation** is processed by the decoding process, **long_term_pic_num** shall be equal to a long-term picture number assigned to one of the reference pictures that is currently marked as "used for long-term reference".

### `long_term_frame_idx`

This member is used with **memory_management_control_operation** equal to 3 or 6 to assign a long-term frame index to a picture. When the associated **memory_management_control_operation** is processed by the decoding process, the value of **long_term_frame_idx** shall be in the range of 0 to *MaxLongTermFrameIdx*, inclusive.

### `max_long_term_frame_idx_plus1`

The value minus 1 specifies the maximum value of long-term frame index allowed for long-term reference pictures (until receipt of another value of **max_long_term_frame_idx_plus1**). The value of **max_long_term_frame_idx_plus1** shall be in the range of 0 to **max_num_ref_frames**, inclusive.

## Remarks

The variable *MaxLongTermFrameIdx* is derived as follows:

* If **max_long_term_frame_idx_plus1** is equal to 0, *MaxLongTermFrameIdx* is set equal to "no long-term frame indices".
* If **max_long_term_frame_idx_plus1** is greater than 0, *MaxLongTermFrameIdx* is set equal to **max_long_term_frame_idx_plus1** − 1.

The operation of marking the current frame as a short-term reference is given by a flag present in the [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_flags_0080) structure with its corresponding **PictureOrderCountNumber** and **FrameDecodingOrderNumber** values indicated in the [associated picture control structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0).

The variable **max_num_ref_frames** is indicated by the maximum decoded picture buffer (DPB) capacity reported.

Note that for marking an instantaneous decoder refresh (IDR) frame as long-term reference, the proposed explicit mechanism is to mark it as short term reference first, by setting [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_FLAG_0080_USED_AS_REFERENCE_PICTURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_picture_control_flags_0080) when calling [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) for the IDR frame, and later promoting it to be a long-term reference frame using memory management operation '3' to mark a short-term reference picture as "used for long-term reference" and assign a long-term frame index to it.

Alternatively, if encoding an IDR frame and setting [**adaptive_ref_pic_marking_mode_flag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0) = 1, the driver assumes that the client is attempting to set the H264 slice header **long_term_reference_flag** and will do so in the output bitstream for the [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) call.

For more details about the picture marking process, see the H.264 specification, section 8.2.5.4 "Adaptive memory control decoded reference picture marking process".

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_h264_0082_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)