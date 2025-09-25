## Description

If a [**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095_flags) value is reported for its respective structure, the driver must write the value after [*EncodeFrame*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) execution with or without modifications (copy API client input) done by the driver. Otherwise, the driver must copy the values from the associated API Client input when calling *EncodeFrame*.

## Members

### `CompoundPredictionType`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_COMPOUND_PREDICTION_MODE**.

### `LoopFilter`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_LOOP_FILTER**.

### `LoopFilterDelta`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_LOOP_FILTER_DELTA**.

### `Quantization`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_QUANTIZATION**.

### `QuantizationDelta`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_QUANTIZATION_DELTA**.

### `CDEF`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_CDEF_DATA**.

### `SegmentationConfig`

This member operates in different modes depending the segmentation mode selected.

* If [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_0095_FLAG_ENABLE_FRAME_SEGMENTATION_AUTO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_0095_flags) is on for the current frame, the driver:
  * Calculates and writes **SegmentationConfig**, which will be used by the API Client to code the segmentation_params() syntax in the frame header.
  * Calculates and writes the read_segment_id() map information directly in the compressed bitstream.
* If **D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_FLAG_ENABLE_FRAME_SEGMENTATION_CUSTOM** is on for the current frame, the driver:
  * Copy here the **SegmentationConfig** sent by the API Client in the encode frame parameters for API Client to code the segmentation_params() syntax in the frame header.
  * Copy the read_segment_id() map sent by the API Client in the encode frame parameters directly in the compressed bitstream.
* Otherwise (both segmentation modes are off):
  * The driver should write all zeroes.
  * API Client will write segmentation_enabled = 0 accordingly in the segmentation_params() section of the frame header.

### `PrimaryRefFrame`

Associated flag is **D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAG_PRIMARY_REF_FRAME**. If the flag was set, the driver controls the selection of the primary reference frame from which the segment id map, CDF, etc are inherited from.

When used together with [**D3D12DDI_VIDEO_ENCODER_AV1_FEATURE_0095_FLAG_AUTO_SEGMENTATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_feature_0095_flags), allows the driver to force a value other than PRIMARY_REF_NONE when applicable, giving the driver full control of the AV1 syntax: segmentation_update_map, segmentation_temporal_update and segmentation_update_data in segmentation_params().

### `ReferenceIndices[7]`

When the flag is reported, the driver may reorder/remap (but not change the number of references) the **ReferenceIndices** array, based on the user input [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_codec_data_0095)**.ReferenceIndices**. Otherwise, the driver must copy each array entry of this parameter as-is from **D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_CODEC_DATA_0095.ReferenceIndices**.

API Client will write the picture header ref_frame_idx AV1 syntax from this output parameter.

## Remarks

See [D3D12 AV1 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12-av1) for more information.

## See also

[**D3D12DDI_VIDEO_ENCODER_AV1_CODEC_CONFIGURATION_SUPPORT_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_codec_configuration_support_0095)

[**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095_flags)