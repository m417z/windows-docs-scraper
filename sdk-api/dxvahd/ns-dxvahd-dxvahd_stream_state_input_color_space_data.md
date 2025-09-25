# DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA structure

## Description

Specifies the color space for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) input stream.

## Members

### `Type`

Specifies whether the input stream contains video or graphics. The device can optimize the processing based on the type. The default state value is 0 (video).

| Value | Meaning |
| --- | --- |
| 0 | Video. |
| 1 | Graphics. |

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

Specifies whether the input stream uses conventional YCbCr or extended YCbCr (xvYCC). The default state value is 0 (conventional YCbCr).

| Value | Meaning |
| --- | --- |
| 0 | Conventional YCbCr. |
| 1 | Extended YCbCr (xvYCC). |

### `Reserved`

### `Value`

## Remarks

The **RGB_Range** member applies to RGB input, while the **YCbCr_Matrix** and **YCbCr_xvYCC** members apply to YCbCr (YUV) input.

In some situations, the device might perform an intermediate color conversion on the input stream. If so, it uses the flags that apply to both color spaces. For example, suppose the device converts from RGB to YCbCr. If the **RGB_Range** member is 0 and the **YCbCr_Matrix** member is 1, the device will convert from full-range RGB to BT.709 YCbCr.

If the device supports xvYCC, it returns the **DXVAHD_DEVICE_CAPS_xvYCC** capability flag in the **DeviceCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. Otherwise, the device ignores the value of **YCbCr_xvYCC** and treats all YCbCr input as conventional YCbCr. To get the device's capabilities, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps).

#### Examples

```cpp
HRESULT DXVAHD_SetInputColorSpace(
    IDXVAHD_VideoProcessor *pVP,
    UINT stream,
    BOOL bPlayback,     // TRUE = playback, FALSE = video processing
    UINT RGB_Range,     // 0 = 0-255, 1 = 16-235
    UINT YCbCr_Matrix,  // 0 = BT.601, 1 = BT.709
    UINT YCbCr_xvYCC    // 0 = Conventional YCbCr, 1 = xvYCC
    )
{
    DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA data =
    {
        bPlayback ? 0 : 1,
        RGB_Range ? 1 : 0,
        YCbCr_Matrix ? 1 : 0,
        YCbCr_xvYCC ? 1 : 0
    };

    HRESULT hr = pVP->SetVideoProcessStreamState(
        stream,
        DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE,
        sizeof(data),
        &data
        );

    return hr;
}

```

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_STREAM_STATE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_stream_state)

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)