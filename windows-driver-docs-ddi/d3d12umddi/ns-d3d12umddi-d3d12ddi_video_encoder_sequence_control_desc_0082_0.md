## Description

The **D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_DESC_0082_0** structure contains the sequence-level parameters for the input of a video encoding operation.

## Members

### `Flags`

A [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_CONTROL_FLAGS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_sequence_control_flags_0082_0) value that indicates the sequence control descriptor flags for the current encode frame operation.

### `IntraRefreshConfig`

A [**D3D12DDI_VIDEO_ENCODER_INTRA_REFRESH_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_intra_refresh_0080) structure that specifies the parameters for the intra-refresh mode that should be used when triggering intra-refresh sessions. See Remarks for details about the use of intra-fresh.

### `RateControl`

A [**D3D12DDI_VIDEO_ENCODER_RATE_CONTROL_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_rate_control_0080_2) structure that specifies the rate control configuration.

Check the [**D3D12_VIDEO_ENCODER_SUPPORT_FLAG_0083_0_RATE_CONTROL_RECONFIGURATION_AVAILABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) flag to determine whether dynamic reconfiguration of rate control is supported:

* If supported, a modified **RateControl** causes the rate control algorithm to restart, with the new configuration starting from the execution of the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command.
* If not supported, **RateControl** should be set at the beginning of the encoding session and not changed during the session.

### `PictureTargetResolution`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_RESOLUTION_DESC_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_resolution_desc_0080) structure that describes the resolution to use when encoding this frame. The target resolution must be set based on the list of resolutions specified when the associated [encoder heap for this operation was created](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2).

Check the [**D3D12_VIDEO_ENCODER_SUPPORT_FLAG_0083_0_RESOLUTION_RECONFIGURATION_AVAILABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) flag to determine whether dynamic reconfiguration for resolution is supported:

* If supported, **PictureTargetResolution** indicates the resolution to use for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command. In some codecs, a change in resolution in the middle of the encoding session might require a GOP to be reset with a potential force IDR/Key frame request, also resetting the decoded picture buffer (DPB) buffer and frame management algorithms.
* If not supported, **PictureTargetResolution** indicates the target resolution for the entire encoding session and must not be changed during the session.

### `SelectedLayoutMode`

A [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE_0080**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_layout_mode_0080) value that indicates which layout mode is being used, and hence which union members to use in **FrameSubregionsLayoutData**.

Check the [**D3D12_VIDEO_ENCODER_SUPPORT_FLAG_0083_0_SUBREGION_LAYOUT_RECONFIGURATION_AVAILABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) flag to determine whether subregion dynamic reconfiguration is supported:

* If supported, **SelectedLayoutMode** indicates the subregion partitioning mode used for the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command.
* If not supported, **SelectedLayoutMode* indicates the target subregion mode of the full encoding session and must not be changed during the encoding session.

### `FrameSubregionsLayoutData`

A [**D3D12DDI_VIDEO_ENCODER_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_picture_control_subregions_layout_data_0080_2) structure that contains picture subregions layout optional codec-specific data. If **SelectedLayoutMode** indicates that there are no subregions, this member must be NULL.

### `CodecGopSequence`

A [**D3D12DDI_VIDEO_ENCODER_SEQUENCE_GOP_STRUCTURE_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_sequence_gop_structure_0082_0) structure that specifies the current GOP used in the video sequence, in display order. Calls to [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) must follow this GOP but in sequence order after B-Frames reordering.

Check the [**D3D12_VIDEO_ENCODER_SUPPORT_FLAG__0083_0_SEQUENCE_GOP_RECONFIGURATION_AVAILABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0) flag to determine whether GOP dynamic reconfiguration is supported:

* If supported, **CodecGopSequence** indicates the new GOP subregion mode used starting at the associated [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command.
* If not supported, **CodecGopSequence** indicates the target GOP pattern (in display order) of the full encoding session and must not be changed during the encoding session.

## Remarks

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

### Using intra-refresh

The use of bidirectional reference frames (B Frames) is mutually exclusive with intra-refresh. The caller should check that **CodecGopSequence**'s structure does not contain B frames if intra-refresh modes are active. When querying for [**D3D12DDICAPS_VIDEO_ENCODER_SUPPORT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicaps_video_encoder_support_data_0083_0) with an intra-refresh mode other than [**D3D12_VIDEO_ENCODER_INTRA_REFRESH_MODE_NONE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_intra_refresh_mode_0080), the **CodecGopSequence** set must not contain B frames, or the query will return no support.

The use of infinite intra-refresh is possible by periodically requesting a new wave of intra-refresh after each of intra-refresh finishes.

When starting an intra-refresh of N frames of duration, the host does the following:

* Sets the corresponding picture control flag to start intra-refresh;
* Controls the frame index between [0..N) in the picture control structure to hint to the driver about the progress of the intra refresh session.

The expected behavior when explicitly requesting an intra-refresh wave with duration N frames follows:

* If the request for intra-refresh happens at the beginning of a GOP, the intra-refresh occurs for N frames and then a new GOP is started with an I frame.

* If the request for intra-refresh happens in the middle of a GOP, the group of pictures will be ended until the last submitted [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) command and restarted after the intra-refresh session with a new GOP starting with an I frame. For example, when the GOP is IPPPP...IPPPP..., if the intra-refresh start is requested at the "IPP" partial submission of the GOP, the last two P frames of that GOP will be ignored, the intra-refresh session will be issued for the N next frames, and then a new key-frame that restarts the GOP structure is expected.

For row-based intra-refresh:

* The configured GOP structure will have to be reconfigured to Infinite IPPP...P... GOP (GOPLength = 0u and PPicturePeriod = 1u) for the duration of the intra-refresh session. It can then be reconfigured again after the intra-refresh wave finished.

* The configured subregion partitioning mode will be reconfigured to correspond with N uniform slices partitioning per frame for a duration of N [**EncodeFrame**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) commands. This is particularly important when the subregion partitioning is set to an incompatible mode with intra-refresh requirements, for example when the row of intra coded units in a slice will disrupt the limitation set to bytes per slice. The expectation for row based intra-refresh is that the resulting frame contains N slices, all P slices, except the current intra-refresh row slice, which has to be an I slice.

## See also

[**D3D12DDI_VIDEO_ENCODER_ENCODEFRAME_INPUT_STREAM_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encodeframe_input_stream_arguments_0082_0)

[**D3D12DDI_VIDEO_ENCODER_SUPPORT_FLAGS_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_support_flags_0083_0)

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)

[**PFND3D12DDI_CREATEVIDEOENCODERHEAP_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createvideoencoderheap_0080_2)