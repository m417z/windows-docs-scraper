# D3D12_VIDEO_PROCESS_LUMA_KEY structure

## Description

Specifies the settings used for luma keying. This value is used with the [D3D12_VIDEO_PROCESS_INPUT_STREAM_DESC](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_process_input_stream_desc) structure.

## Members

### `Enable`

A boolean value specifying whether luma keying is enabled.

### `Lower`

The lower bound for the luma key. The valid range is [0…1]. If *Enable* is FALSE, this parameter is ignored.

### `Upper`

The upper bound for the luma key. The valid range is [0…1]. If *Enable* is FALSE, this parameter is ignored.

## Remarks

The values of *Lower* and *Upper* give the lower and upper bounds of the luma key, using a nominal range of [0...1]. Given a format with n bits per channel, these values are converted to luma values as follows:

`val = f * ((1 << n)-1)`

Any pixel whose luma value falls within the upper and lower bounds (inclusive) is treated as transparent. For example, if the pixel format uses 8-bit luma, the upper bound is calculated as follows:

`BYTE Y = BYTE(max(min(1.0, Upper), 0.0) * 255.0)`

Note that the value is clamped to the range [0...1] before multiplying by 255.

## See also