## Description

The **PFND3D12DDI_VIDEO_ENCODE_RESOLVE_OUTPUT_METADATA_0082_0** callback function records a command to resolve the output metadata of an [encoding operation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0) into a readable format.

## Parameters

### `hDrvCommandList` [in]

Handle to the driver's data for the command list. The driver uses this region of memory to store internal data structures that are related to its command list.

### `pInputArguments` [in]

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS_0080_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_input_arguments_0080_2) structure that contains input arguments for this callback.

### `pOutputArguments` [out]

Pointer to a [**D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_OUTPUT_ARGUMENTS_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_output_arguments_0082_0) structure in which to store output from this callback.

## Remarks

For all encoders, the driver must position all layout information contiguously in memory in the [**ResolvedLayoutEncoderMetadataDrvBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_encode_operation_metadata_buffer_0080_2). The API Client will parse this metadata accordingly depending on the encoder type ([**D3D12DDI_VIDEO_ENCODER_RESOLVE_METADATA_INPUT_ARGUMENTS_0080_2.EncoderCodec**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_input_arguments_0080_2) at the driver level).

### ResolvedLayoutEncoderMetadataDrvBuffer for H264/HEVC codecs

For H264 and HEVC encoders (types supported before the AV1 extension was added), the resolved buffer memory layout isn't changed.

* [**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0) structure
* **WrittenSubregionsCount** elements of type [**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_frame_subregion_metadata_0083_0) indicating each tile in the same order they're written in the compressed output bitstream.

* The caller can infer the maximum size of the resolved metadata buffer by the H264/HEVC layout for **ResolveEncoderOutputMetadata**:

  * maxSliceNumber = [**D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2.MaxSubregionsNumber**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolution_support_limits_0080_2);
  * MaxEncoderOutputMetadataResolvedBufferSize = sizeof(**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**) + (maxSliceNumber * sizeof(**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0**))

### ResolvedLayoutEncoderMetadataDrvBuffer for AV1 codec

For AV1 encoding ([**pInputArguments->EncoderCodec**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_resolve_metadata_input_arguments_0080_2) equal to **D3D12DDI_VIDEO_ENCODER_CODEC_0095_AV1**), which was added in Windows 11, version 24H2 (WDDM 3.2), the driver should use the added AV1-specific resolved buffer layout.

* The memory layout is defined as:
  * [**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_output_metadata_0083_0) structure

  * **WrittenSubregionsCount** elements of type **D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0** indicating each tile in the same order they're written in the compressed output bitstream.
    * bSize = tile_size_minus_1 + 1 + bStartOffset
    * bStartOffset = Bytes to skip relative to this tile, the actual bitstream coded tile size is tile_size_minus_1 = (bSize - bStartOffset - 1).
    * bHeaderSize = 0
    * The i-th tile is read from the compressed_bitstream[offset] with offset = [sum j = (0, (i-1)){ tile[j].bSize }] + tile[i].bStartOffset
  * The [**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_picture_control_subregions_layout_data_tiles_0095)
structure indicating the encoded frame tile grid structure
  * [**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_video_encoder_av1_post_encode_values_0095) structure indicating encoding metadata values that are only obtained post-execution of *EncodeFrame* on the GPU.

* The caller can infer the maximum size of the resolved metadata buffer by the layout for AV1 in **ResolveEncoderOutputMetadata**.

  * MaxTiles = **D3D12DDI_VIDEO_ENCODER_RESOLUTION_SUPPORT_LIMITS_0080_2.MaxSubregionsNumber**;
  * **MaxEncoderOutputMetadataResolvedBufferSize** =
sizeof(**D3D12DDI_VIDEO_ENCODER_OUTPUT_METADATA_0083_0**) +
(MaxTiles * sizeof(**D3D12DDI_VIDEO_ENCODER_FRAME_SUBREGION_METADATA_0083_0**));
+ sizeof(**D3D12DDI_VIDEO_ENCODER_AV1_PICTURE_CONTROL_SUBREGIONS_LAYOUT_DATA_TILES_0095**)
+ sizeof(**D3D12DDI_VIDEO_ENCODER_AV1_POST_ENCODE_VALUES_0095**)

See [D3D12 video encoding](https://learn.microsoft.com/windows-hardware/drivers/display/video-encoding-d3d12) for general information.

## See also

[**PFND3D12DDI_VIDEO_ENCODE_FRAME_0082_0**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_video_encode_frame_0082_0)