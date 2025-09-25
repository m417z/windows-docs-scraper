# DXVAHD_STREAM_STATE enumeration

## Description

Specifies state parameters for an input stream to a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

To set a state parameter, call [IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate). This method takes a **DXVAHD_STREAM_STATE** value and a byte array as input. The byte array contains state data, the structure of which is defined by the **DXVAHD_STREAM_STATE** value.

## Constants

### `DXVAHD_STREAM_STATE_D3DFORMAT:0`

Specifies the video format of the input stream. The state data is a [DXVAHD_STREAM_STATE_D3DFORMAT_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_d3dformat_data) structure.

### `DXVAHD_STREAM_STATE_FRAME_FORMAT:1`

Specifies how the input stream is interlaced. The state data is a [DXVAHD_STREAM_STATE_FRAME_FORMAT_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_stream_state_frame_format_data) structure.

### `DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE:2`

Specifies the color space for the input stream. The state data is a [DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_stream_state_input_color_space_data) structure.

### `DXVAHD_STREAM_STATE_OUTPUT_RATE:3`

Specifies the output frame rate. The state data is a [DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_output_rate_data) structure.

### `DXVAHD_STREAM_STATE_SOURCE_RECT:4`

Specifies the source rectangle. The source rectangle defines which portion of the input sample is blitted to the destination surface. The state data is a [DXVAHD_STREAM_STATE_SOURCE_RECT_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_source_rect_data) structure.

### `DXVAHD_STREAM_STATE_DESTINATION_RECT:5`

Specifies the destination rectangle. The destination rectangle defines which portion of the destination rectangle receives the blit. The state data is a [DXVAHD_STREAM_STATE_DESTINATION_RECT_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_stream_state_destination_rect_data) structure.

### `DXVAHD_STREAM_STATE_ALPHA:6`

Specifies the planar alpha value for this input stream. The state data is a [DXVAHD_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_alpha_data) structure.

### `DXVAHD_STREAM_STATE_PALETTE:7`

Specifies the color-palette entries. The state data is a [DXVAHD_STREAM_STATE_PALETTE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_palette_data) structure.

 This setting is used for palettized input formats, such as AI44 and IA44.

### `DXVAHD_STREAM_STATE_LUMA_KEY:8`

Specifies the luma key. The state data is a [DXVAHD_STREAM_STATE_LUMA_KEY_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_luma_key_data) structure.

This state is applicable only if the device supports luma keying. To find out if the device supports luma keying, check for the **DXVAHD_FEATURE_CAPS_LUMA_KEY** flag in the **FeatureCaps**  member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) capabilities structure.

### `DXVAHD_STREAM_STATE_ASPECT_RATIO:9`

Specifies the pixel aspect ratio of the source and destination surfaces. The state data is a [DXVAHD_STREAM_STATE_ASPECT_RATIO_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_stream_state_aspect_ratio_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_BRIGHTNESS:100`

Specifies the brightness filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_CONTRAST:101`

Specifies the contrast filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_HUE:102`

Specifies the hue filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_SATURATION:103`

Specifies the saturation filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_NOISE_REDUCTION:104`

Specifies the noise-reduction filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_EDGE_ENHANCEMENT:105`

Specifies the edge-enhancement filter. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_FILTER_ANAMORPHIC_SCALING:106`

Specifies the anamorphic-scaling value. The state data is a [DXVAHD_STREAM_STATE_FILTER_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_filter_data) structure.

### `DXVAHD_STREAM_STATE_PRIVATE:1000`

Specifies that the state data contains a private DXVA-HD stream state. The state data is a [DXVAHD_STREAM_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_private_data) structure.

Use this state for proprietary or device-specific parameters.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[IDXVAHD_VideoProcessor::GetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-getvideoprocessstreamstate)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)