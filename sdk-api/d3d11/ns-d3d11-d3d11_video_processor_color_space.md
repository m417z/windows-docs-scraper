# D3D11_VIDEO_PROCESSOR_COLOR_SPACE structure

## Description

Specifies the color space for video processing.

## Members

### `Usage`

Specifies whether the output is intended for playback or video processing (such as editing or authoring). The device can optimize the processing based on the type. The default state value is 0 (playback).

| Value | Meaning |
| --- | --- |
| 0 | Playback |
| 1 | Video processing |

### `RGB_Range`

Specifies the RGB color range. The default state value is 0 (full range).

| Value | Meaning |
| --- | --- |
| 0 | Full range (0-255) |
| 1 | Limited range (16-235) |

### `YCbCr_Matrix`

Specifies the YCbCr transfer matrix. The default state value is 0 (BT.601).

| Value | Meaning |
| --- | --- |
| 0 | ITU-R BT.601 |
| 1 | ITU-R BT.709 |

### `YCbCr_xvYCC`

Specifies whether the output uses conventional YCbCr or extended YCbCr (xvYCC). The default state value is zero (conventional YCbCr).

| Value | Meaning |
| --- | --- |
| 0 | Conventional YCbCr |
| 1 | Extended YCbCr (xvYCC) |

### `Nominal_Range`

Specifies the [D3D11_VIDEO_PROCESSOR_NOMINAL_RANGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_nominal_range).

Introduced in Windows 8.1.

### `Reserved`

Reserved. Set to zero.

## Remarks

The **RGB_Range** member applies to RGB output, while the **YCbCr_Matrix** and **YCbCr_xvYCC** members apply to YCbCr output. If the driver performs color-space conversion on the background color, it uses the values that apply to both color spaces.

If the driver supports extended YCbCr (xvYCC), it returns the **D3D11_VIDEO_PROCESSOR_DEVICE_CAPS_xvYCC** capabilities flag in the [ID3D11VideoProcessorEnumerator::GetVideoProcessorCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videoprocessorenumerator-getvideoprocessorcaps) method. Otherwise, the driver ignores the value of **YCbCr_xvYCC** and treats all YCbCr output as conventional YCbCr.

If extended YCbCr is supported, it can be used with either transfer matrix. Extended YCbCr does not change the black point or white point—the black point is still 16 and the white point is still 235. However, extended YCbCr explicitly allows blacker-than-black values in the range 1–15, and whiter-than-white values in the range 236–254. When extended YCbCr is used, the driver should not clip the luma values to the nominal 16–235 range.

## See also

[Direct3D 11 Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-structures)