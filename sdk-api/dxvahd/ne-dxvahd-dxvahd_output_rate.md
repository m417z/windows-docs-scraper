# DXVAHD_OUTPUT_RATE enumeration

## Description

Specifies the output frame rates for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

This enumeration type is used in the [DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_output_rate_data) structure.

## Constants

### `DXVAHD_OUTPUT_RATE_NORMAL:0`

The frame output is at the normal rate.

For progressive input, every frame produces one output frame. For interlaced input, every frame (two fields) produces two progressive output frames.

### `DXVAHD_OUTPUT_RATE_HALF:1`

The frame output is at half rate.

For progressive input, every frame produces one output frame, just as with **DXVAHD_OUTPUT_RATE_NORMAL**. For interlaced input, every frame produces one progressive output frame.

### `DXVAHD_OUTPUT_RATE_CUSTOM:2`

Frame output is at a custom rate.

 Use this value for frame-rate conversion or inverse telecine. The exact rate is given in the **OutputRate** member of the [DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_output_rate_data) structure. To get the list of custom rates supported by the video processor, call the [IDXVAHD_Device::GetVideoProcessorCustomRates](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcustomrates) method.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_output_rate_data)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)