# DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA structure

## Description

Specifies the output frame rate for an input stream when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `RepeatFrame`

Specifies how the device performs frame-rate conversion, if required. The default state value is **FALSE** (interpolation).

| Value | Meaning |
| --- | --- |
| **TRUE** | The device repeats frames. |
| **FALSE** | The device interpolates frames. |

### `OutputRate`

Specifies the output rate, as a member of the [DXVAHD_OUTPUT_RATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_output_rate) enumeration.

### `CustomRate`

Specifies a custom output rate, as a [DXVAHD_RATIONAL](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_rational) structure. This member is ignored unless **OutputRate** equals **DXVAHD_OUTPUT_RATE_CUSTOM**. The default state value is 1/1.

To get the list of custom rates supported by the video processor, call [IDXVAHD_Device::GetVideoProcessorCustomRates](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessorcustomrates). If a custom rate is used, it must be taken from this list.

## Remarks

The output rate might require the device to convert the frame rate of the input stream. If so, the value of **RepeatFrame** controls whether the device creates interpolated frames or simply repeats input frames.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)