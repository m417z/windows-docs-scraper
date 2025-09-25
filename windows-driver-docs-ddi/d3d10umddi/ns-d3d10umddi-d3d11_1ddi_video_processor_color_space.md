# D3D11_1DDI_VIDEO_PROCESSOR_COLOR_SPACE structure

## Description

Specifies the color space for video processing.

## Members

### `Usage`

Specifies whether the output is intended for playback or video processing (such as editing or authoring). The device can optimize the processing based on the type. The default state value is 0 (playback).

|Value|Meaning|
|--- |--- |
|0|Playback|
|1|Video processing|

### `RGB_Range`

Specifies the RGB color range. The default state value is 0 (full range).

|Value|Meaning|
|--- |--- |
|0|Full range (0-255)|
|1|Limited range (16-235)|

### `YCbCr_Matrix`

Specifies the YCbCr transfer matrix. The default state value is 0 (BT.601).

|Value|Meaning|
|--- |--- |
|0|ITU-R BT.601|
|1|ITU-R BT.709|

### `YCbCr_xvYCC`

Specifies whether the output uses conventional YCbCr or extended YCbCr (xvYCC). The default state value is zero (conventional YCbCr).

|Value|Meaning|
|--- |--- |
|0|Conventional YCbCr|
|1|Extended YCbCr (xvYCC)|

### `Nominal_Range` [in]

A UINT value that specifies that the luminance range of YUV data is described by the [D3D11_1DDI_VIDEO_PROCESSOR_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_nominal_range) enumeration. The default state value is zero, which indicates the studio luminance range of 16 to 235, inclusive [16, 235].

When YUV-format data is converted to RGB format, the luminance range specified by [D3D11_1DDI_VIDEO_PROCESSOR_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_nominal_range) is applied to the YUV data before the conversion to RGB.

For more information on luminance range, see [YUV format ranges in Windows 8.1](https://learn.microsoft.com/windows-hardware/drivers/display/yuv-format-ranges).

Supported starting with Windows 8.1.

### `Reserved`

Reserved for system use. Set to zero.

## See also

[D3D11_1DDI_VIDEO_PROCESSOR_NOMINAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d11_1ddi_video_processor_nominal_range)