## Description

The **D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_DESC_0082_0** structure contains the picture-level parameters for the input of an encoding operation.

## Members

### `IntraRefreshFrameIndex`

When requesting an intra-refresh wave for *IntraRefreshFramesDuration* frames by specifying the [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAG_0080_REQUEST_INTRA_REFRESH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_sequence_control_flags_0082_0) flag, this value indicates, for the current picture, the index of the frame in the intra-refresh wave. The value range is set by the host to be between [0-*IntraRefreshFramesDuration*) to hint the status of the intra-refresh session to the driver.

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_FLAGS_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_picture_control_flags_0080) value that indicates the picture control descriptor flags for the current encode frame operation.

### `PictureControlCodecData`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0) structure that contains picture-control codec-specific data. Depending on the selected [rate control mode](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_mode_0080), the quantization parameter (QP) values are interpreted differently.

### `ReferenceFrames`

A [**D3D12DDI_VIDEO_ENCODE_REFERENCE_FRAMES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encode_reference_frames_0080) structure that contains the reconstructed pictures from the past encoding operations outputs.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

The following remarks provide guidance for frame management.

The host calls [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) in encode order based on the picture type periodic sequence configured in the codec group of pictures (GOP) structure after doing the B-frame reordering by POC if needed.

Different codecs can use their own ways of indexing this structure and keeping their state metadata. Refer to the codec picture parameters also passed in the [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) operation that contain such details.

[**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAG_0082_0_RECONSTRUCTED_FRAMES_REQUIRE_CONTIGUOUS_TEXTURE_ARRAYS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) specifies the requirement of texture arrays for the **hDrvTexture2Ds** and **pSubresources** fields of the [**D3D12DDI_VIDEO_ENCODE_REFERENCE_FRAMES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encode_reference_frames_0080) structure.

The output of the encode operation for a given frame must also return the reconstructed picture if it is marked to be used as reference in next frames. The client passes the reconstructed pictures in future [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) commands.

If coding temporal layers, a picture can only be used as a reference picture on **TemporalLayerIndex** layers that are less than its own layer number. The temporal layer indices are specified in the picture control structure and in the reference picture descriptors.

The hardware limitations for the number of reference pictures are expressed in terms of the maximum number of elements present in L0 (**MaxL0ReferencesForP**/**MaxL0ReferencesForB**) and L1 (**MaxL1ReferencesForB**) lists, and limiting by **MaxDPBCapacity** the maximum number of unique indices in (L0 union L1) that map into the value of **pReferenceFramesReconPictureDescriptors** provided in [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0).

There's no limitation to the number of decoded picture buffer (DPB) entries being passed in **pReferenceFramesReconPictureDescriptors**, but instead in the number of entries on that array being references by the L0 and L1 lists. This allows the user to track the state of a DPB in **pReferenceFramesReconPictureDescriptors** within the restrictions defined by the codec standard limitations and only use a subset restricted by the hardware limitations when calling [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0). For example, for HEVC encoding, the caller could keep track of the latest 15 encoded pictures in **pReferenceFramesReconPictureDescriptors** but only use a subset of the pictures that falls within the hardware restrictions, by assigning a limited number of unique indices in the L0 and L1 lists.

Note that a request for an instantaneous decoder refresh (IDR) frame will act as a barrier between frame references and the DPB buffer and its state might need to be flushed accordingly by the host.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0)

[**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_CODEC_DATA_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_codec_data_0082_0)

[**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_rate_control_mode_0080)

[**D3D12DDI_VIDEO_ENCODE_REFERENCE_FRAMES_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encode_reference_frames_0080)

[**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_sequence_control_flags_0082_0)

[**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)