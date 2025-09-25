# DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA structure

## Description

Specifies the output color space for blit operations, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Usage`

Specifies whether the output is intended for playback or video processing (such as editing or authoring). The device can optimize the processing based on the type. The default state value is 0 (playback).

| Value | Meaning |
| --- | --- |
| 0 | Playback. |
| 1 | Video processing. |

### `RGB_Range`

Specifies the RGB color range. The default state value is 0 (full range).

| Value | Meaning |
| --- | --- |
| 0 | Full range (0-255). |
| 1 | Limited range (16-235). |

### `YCbCr_Matrix`

Specifies the YCbCr transfer matrix. The default state value is 0 (BT.601).

| Value | Meaning |
| --- | --- |
| 0 | ITU-R BT.601. |
| 1 | ITU-R BT.709. |

### `YCbCr_xvYCC`

Specifies whether the output uses conventional YCbCr or extended YCbCr (xvYCC). The default state value is zero (conventional YCbCr).

| Value | Meaning |
| --- | --- |
| 0 | Conventional YCbCr. |
| 1 | Extended YCbCr (xvYCC). |

### `Reserved`

### `Value`

## Remarks

The **RGB_Range** member applies to RGB output, while the **YCbCr_Matrix** and **YCbCr_xvYCC** members apply to YCbCr (YUV) output. If the device performs color-space conversion on the background color, it uses the values that apply to both color spaces.

Extended YCbCr can be used with either transfer matrix. Extended YCbCr does not change the black point or white point—the black point is still 16 and the white point is still 235. However, extended YCbCr explicitly allows blacker-than-black values in the range 1–15, and whiter-than-white values in the range 236–254. When extended YCbCr is used, the driver should not clip the luma values to the nominal 16–235 range.

If the device supports extended YCbCr, it sets the **DXVAHD_DEVICE_CAPS_xvYCC** capability flag in the **DeviceCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. Otherwise, the device ignores the value of the **YCbCr_xvYCC** member and treats all YCbCr output as conventional YCbCr. To get the device's capabilities, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps).

If the output format is a wide-gamut RGB format, output might fall outside the nominal [0...1] range of sRGB. This is particularly true if one or more input streams use extended YCbCr.

#### Examples

```cpp
HRESULT DXVAHD_SetOutputColorSpace(
    IDXVAHD_VideoProcessor *pVP,
    BOOL bPlayback,     // TRUE = playback, FALSE = video processing
    UINT RGB_Range,     // 0 = 0-255, 1 = 16-235
    UINT YCbCr_Matrix,  // 0 = BT.601, 1 = BT.709
    UINT YCbCr_xvYCC    // 0 = Conventional YCbCr, 1 = xvYCC
    )
{
    DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA data =
    {
        bPlayback ? 0 : 1,
        RGB_Range ? 1 : 0,
        YCbCr_Matrix ? 1 : 0,
        YCbCr_xvYCC ? 1 : 0
    };

    HRESULT hr = pVP->SetVideoProcessBltState(
        DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE,
        sizeof(data),
        &data
        );

    return hr;
}

```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_blt_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)