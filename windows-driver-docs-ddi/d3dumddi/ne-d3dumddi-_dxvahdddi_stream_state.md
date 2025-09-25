# _DXVAHDDDI_STREAM_STATE enumeration

## Description

The DXVAHDDDI_STREAM_STATE enumeration contains values that identify the stream-state data for a video processor.

## Constants

### `DXVAHDDDI_STREAM_STATE_FRAME_FORMAT`

The stream-state data specifies the frame format of the input in a [DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_frame_format_data) structure.

### `DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE`

The stream-state data specifies the color space of the input in a [DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_input_color_space_data) structure.

### `DXVAHDDDI_STREAM_STATE_OUTPUT_RATE`

The stream-state data specifies the output rate of the input in a [DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data) structure.

### `DXVAHDDDI_STREAM_STATE_SOURCE_RECT`

The stream-state data specifies the source rectangle of the input in a [DXVAHDDDI_STREAM_STATE_SOURCE_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_source_rect_data) structure.

### `DXVAHDDDI_STREAM_STATE_DESTINATION_RECT`

The stream-state data specifies the destination rectangle in a [DXVAHDDDI_STREAM_STATE_DESTINATION_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_destination_rect_data) structure.

### `DXVAHDDDI_STREAM_STATE_ALPHA`

The stream-state data specifies the alpha blend level per-plane in a [DXVAHDDDI_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_alpha_data) structure.

### `DXVAHDDDI_STREAM_STATE_PALETTE`

The stream-state data specifies the palette entries of the input in a [DXVAHDDDI_STREAM_STATE_PALETTE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_palette_data) structure.

### `DXVAHDDDI_STREAM_STATE_LUMA_KEY`

The stream-state data specifies the luma key of the input in a [DXVAHDDDI_STREAM_STATE_LUMA_KEY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_luma_key_data) structure.

### `DXVAHDDDI_STREAM_STATE_ASPECT_RATIO`

The stream-state data specifies the aspect ratio of the input in a [DXVAHDDDI_STREAM_STATE_ASPECT_RATIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_aspect_ratio_data) structure.

### `DXVAHDDDI_STREAM_STATE_ROTATION`

The stream-state data specifies the clockwise rotation of the display output surface in a [DXVAHDDDI_STREAM_STATE_ROTATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_rotation_data) structure.

Supported starting with Windows 8.

### `DXVAHDDDI_STREAM_STATE_FILTER_BRIGHTNESS`

The stream-state data specifies the brightness ProcAmp level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_CONTRAST`

The stream-state data specifies the contrast ProcAmp level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_HUE`

The stream-state data specifies the hue ProcAmp level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_SATURATION`

The stream-state data specifies the saturation ProcAmp level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_NOISE_REDUCTION`

The stream-state data specifies the noise reduction filter level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_EDGE_ENHANCEMENT`

The stream-state data specifies the edge enhancement filter level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_FILTER_ANAMORPHIC_SCALING`

The stream-state data specifies the anamorphic scaling level in a [DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data) structure.

### `DXVAHDDDI_STREAM_STATE_PRIVATE`

The stream-state data specifies private parameters in a [DXVAHDDDI_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_private_data) structure.

## Remarks

A DXVAHDDDI_STREAM_STATE-typed value is specified in the **State** member of the [D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate) structure in a call to the [SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate) function to set the stream state for a video processor. Stream-state data that corresponds to the supplied DXVAHDDDI_STREAM_STATE-typed value is pointed to by the **pData** member of D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE.

## See also

[D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_dxvahd_setvideoprocessstreamstate)

[DXVAHDDDI_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_alpha_data)

[DXVAHDDDI_STREAM_STATE_ASPECT_RATIO_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_aspect_ratio_data)

[DXVAHDDDI_STREAM_STATE_DESTINATION_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_destination_rect_data)

[DXVAHDDDI_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_filter_data)

[DXVAHDDDI_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_frame_format_data)

[DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_input_color_space_data)

[DXVAHDDDI_STREAM_STATE_LUMA_KEY_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_luma_key_data)

[DXVAHDDDI_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_output_rate_data)

[DXVAHDDDI_STREAM_STATE_PALETTE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_palette_data)

[DXVAHDDDI_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_private_data)

[DXVAHDDDI_STREAM_STATE_ROTATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_rotation_data)

[DXVAHDDDI_STREAM_STATE_SOURCE_RECT_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_stream_state_source_rect_data)

[SetVideoProcessStreamState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_dxvahd_setvideoprocessstreamstate)