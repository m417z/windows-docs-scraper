## Description

Represents the picture level control elements for the associated [EncodeFrame](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videoencodecommandlist2-encodeframe) command for H.264 encoding.

## Members

### `Flags`

A bitwise OR combination of values from the [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264_flags) enumeration specifying configuration flags for the frame being encoded.

### `FrameType`

A value from the [D3D12_VIDEO_ENCODER_FRAME_TYPE_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_frame_type_h264) enumeration specifying the picture type. Make sure that the codec-specific flags support the specified type. This selection must be kept in sync with the GOP structure configuration set by the host. Note that the GOP is defined in display order and this pic type selection must follow the GOP, but in encode order.

### `pic_parameter_set_id`

A **UINT** specifying the value to be used in the slice headers of the current frame to reference the PPS.

### `idr_pic_id`

When **FrameType** is **D3D12_VIDEO_ENCODER_FRAME_TYPE_H264_IDR_FRAME**, a **UINT** indicating the identifier of the IDR frame to be used in all the slices headers present in the frame.

### `PictureOrderCountNumber`

A **UINT** specifying the current frame display order.

### `FrameDecodingOrderNumber`

A **UINT** specifying the frame decode order with semantic as indicated by the slice header frame_num syntax element that increments after each reference picture.

### `TemporalLayerIndex`

A **UINT** specifying the picture layer number in temporal hierarchy. Check for the maximum number of layers in [D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_codec_configuration_support_h264).

### `List0ReferenceFramesCount`

A **UINT** specifying the number of past frame references to be used for this frame. This value should be coherent with what was exposed in **D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264**.

### `pList0ReferenceFrames`

A pointer to a **UINT** array specifying the list of past frame reference frames to be used for this frame. Each integer value in this array indices into *pReferenceFramesReconPictureDescriptors* to reference pictures kept in the DPB.

### `List1ReferenceFramesCount`

A **UINT** specifying the number of future frame references to be used for this frame. This value should be coherent with what was exposed in **D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT_H264**.

### `pList1ReferenceFrames`

A pointer to a **UINT** array specifying the list of future frame reference frames to be used for this frame. Each integer value in this array indices into *pReferenceFramesReconPictureDescriptors* to reference pictures kept in the DPB.

### `ReferenceFramesReconPictureDescriptorsCount`

A **UINT** specifying the number of entries in *pReferenceFramesReconPictureDescriptors*.

### `pReferenceFramesReconPictureDescriptors`

A pointer to a **UINT** array that describes the current state of the DPB buffer kept in [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC.ReferenceFrames](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_desc). The *pList0ReferenceFrames* and *pList1ReferenceFrames* lists indices map from past/future references into this descriptors array.

This array of descriptors, in turn, maps a reference picture for this frame into a resource index in the reconstructed pictures array **D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC.ReferenceFrames**. Additionally, for each reference picture it indicates the encode and display order number and whether it is a long term reference.

The size of this array always matches **D3D12_VIDEO_ENCODER_PICTURE_CONTROL_DESC.ReferenceFrames.NumTextures** for the associated **EncodeFrame** command.

### `adaptive_ref_pic_marking_mode_flag`

A **UCHAR** defining a semantic mode for the frame reference handling.

| adaptive_ref_pic_marking_mode_flag value | Reference picture marking mode specified |
|-------------------------------------------|------------------------------------------|
| 0 | 1 |
| Sliding window reference picture marking mode: A marking mode providing a first-in first-out mechanism for short-term reference pictures. | Adaptive reference picture marking mode: A reference picture marking mode providing syntax elements to specify marking of reference pictures as "unused for reference" and to assign long-term frame indices. |

### `RefPicMarkingOperationsCommandsCount`

 A **UINT** specifying the number of reference pictures marking operations associated with the current frame. Requires that *adaptive_ref_pic_marking_mode_flag* is set to 1.

### `pRefPicMarkingOperationsCommands`

A pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_MARKING_OPERATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264_reference_picture_marking_operation) structures representing the list of reference pictures marking operations associated with the current frame. The operations described by this list need to be reflected in the DPB descriptors accordingly during the encoding session.

### `List0RefPicModificationsCount`

A **UINT** specifying the number of items in *pList0RefPicModifications*.

### `pList0RefPicModifications`

A pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_LIST_MODIFICATION_OPERATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264_reference_picture_list_modification_operation) structures representing the list of reference picture list modification operations for the *pList0ReferenceFrames* list.

### `List1RefPicModificationsCount`

A **UINT** specifying the number of items in *pList1RefPicModifications*.

### `pList1RefPicModifications`

A pointer to an array of [D3D12_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_H264_REFERENCE_PICTURE_LIST_MODIFICATION_OPERATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_encoder_picture_control_codec_data_h264_reference_picture_list_modification_operation) structures representing the list of reference picture list modification operations for the *pList1ReferenceFrames* list.

### `QPMapValuesCount`

A **UINT** specifying the number of elements present in *pRateControlQPMap*. This should match the number of coding blocks in the frame, rounding up the frame resolution to the closest aligned values.

### `pRateControlQPMap`

A pointer to an array of **Int8** containing, in row/column scan order, the QP map values to use on each squared region for this frame. The QP map dimensions can be calculated using the current resolution and [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS.QPMapRegionPixelsSize](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resolution_support_limits) conveying the squared region sizes.

## Remarks

Note that if the current frame is marked as a reference picture, the output must contain the reconstructed picture along with the bitstream for the host to place it in future commands in the reconstructed pictures reference list. Note that there might be limitations for some frame types to be marked as references, check feature support before setting those values.

The following tables list the expected SPS and PPS Values for H264 encoding.

### Level_idc mappings for H264

| D3D12 Level | Expected level_idc | Notes |
|--------|------------|------------|
D3D12_VIDEO_ENCODER_LEVELS_H264_1 | 10 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_1b | 11 | SPS.constraint_set3 must be 1 |
D3D12_VIDEO_ENCODER_LEVELS_H264_11 | 11 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_12 | 12 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_13 | 13 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_2 | 20 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_21 | 21 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_22 | 22 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_3 | 30 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_31 | 31 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_32 | 32 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_4 | 40 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_41 | 41 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_42 | 42 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_5 | 50 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_51 | 51 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_52 | 52 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_6 | 60 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_61 | 61 | None |
D3D12_VIDEO_ENCODER_LEVELS_H264_62 | 62 | None |

---

### H264 Sequence Parameter Set expected values

| Syntax element | Expected default value | Notes |
|--------|------------|------------|
profile_idc | Enum value of H264_PROFILE_MAIN/H264_PROFILE_HIGH/H264_PROFILE_HIGH10 | None |
constraint_set0_flag | 0 | None |
constraint_set1_flag | 0 | None |
constraint_set2_flag | 0 | None |
constraint_set3_flag | 0 | 1 if using D3D12_VIDEO_ENCODER_LEVELS_H264_1b |
constraint_set4_flag | 0 | None |
constraint_set5_flag | 0 | None |
reserved_zero_2bits | 0 | None |
level_idc | Please see table above for H264 levels | None |
seq_parameter_set_id | User specific | None |
chroma_format_idc | 1 | For usage with P010 or NV12 YUV 4.2.0 formats only |
bit_depth_luma_minus8 | 0 for NV12, 2 for P010 | None |
qpprime_y_zero_transform_bypass_flag | 0 | None |
seq_scaling_matrix_present_flag | 0 | None |
log2_max_frame_num_minus4 | Same as in D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264 | None |
pic_order_cnt_type | Same as in D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264 | Only modes 0 and 2 supported in this API |
log2_max_pic_order_cnt_lsb_minus4 | Same as in D3D12_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_H264 | Only if pic_order_cnt_type == 0 |
max_num_ref_frames | Max number of reference pictures used in encode session | None |
gaps_in_frame_num_value_allowed_flag | 0 | None |
pic_width_in_mbs_minus1 | std::ceil(sequenceTargetResolution.Width / 16.0)) - 1; | None |
pic_height_in_map_units_minus1 | std::ceil(sequenceTargetResolution.Height / 16.0)) - 1; | None |
frame_mbs_only_flag | 0 | No interlace support |
direct_8x8_inference_flag | Based on D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_USE_ADAPTIVE_8x8_TRANSFORM | None |
frame_cropping_flag | 0 or 1 depending on encode resolution being 16 aligned or not | None |
frame_cropping_rect_left_offset | 0 | Only if frame_cropping_flag = 1 |
frame_cropping_rect_right_offset | ((pic_width_in_mbs_minus1+1) * 16 - sequenceTargetResolution.Width) / 2 | Only if frame_cropping_flag = 1 |
frame_cropping_rect_top_offset | ((pic_height_in_map_units_minus1+1) * 16 - sequenceTargetResolution.Height) / 2 | Only if frame_cropping_flag = 1 |
frame_cropping_rect_bottom_offset | 0 | Only if frame_cropping_flag = 1 |
vui_paramenters_present_flag | 0 | None |

### H264 Picture Parameter Set expected values

| Syntax element | Expected default value | Notes |
|--------|------------|------------|
pic_parameter_set_id | User specific | None |
seq_parameter_set_id | User specific | None |
entropy_coding_mode_flag | Based on D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_ENABLE_CABAC_ENCODING | None |
pic_order_present_flag | 0 | Only support for pic_cnt_type = 0, 2 |
num_slice_groups_minus1 | 0 | None |
num_ref_idx_l1_active_minus1 | std::max(static_cast\<INT>(pictureControl.List0ReferenceFramesCount) - 1, 0) | None |
num_ref_idx_l0_active_minus1 | std::max(static_cast\<INT>(pictureControl.List1ReferenceFramesCount) - 1, 0) | None |
weighted_pred_flag | 0 | None |
weighted_bipred_idc | 0 | None |
pic_init_qp_minus26 | 0 | None |
pic_init_qs_minus26 | 0 | None |
chroma_qp_index_offset | 0 | None |
deblocking_filter_control_present_flag | 1 | None |
constrained_intra_pred_flag | Based on D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_USE_CONSTRAINED_INTRAPREDICTION | None |
redundant_pic_cnt_present_flag | 0 | None |
transform_8x8_mode_flag | Based on D3D12_VIDEO_ENCODER_CODEC_CONFIGURATION_H264_FLAG_USE_ADAPTIVE_8x8_TRANSFORM | Only if using High profiles |
pic_scaling_matrix_present_flag | 0 | None |
second_chroma_qp_index_offset | 0 | None |

## See also