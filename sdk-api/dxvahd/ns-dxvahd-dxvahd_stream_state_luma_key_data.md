# DXVAHD_STREAM_STATE_LUMA_KEY_DATA structure

## Description

Specifies the luma key for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Enable`

If **TRUE**, luma keying is enabled. Otherwise, luma keying is disabled. The default value is **FALSE**.

### `Lower`

The lower bound for the luma key. The range is [0…1]. The default state value is 0.0.

### `Upper`

The upper bound for the luma key. The range is [0…1]. The default state value is 0.0.

## Remarks

To use this state, the device must support luma keying, indicated by the **DXVAHD_FEATURE_CAPS_LUMA_KEY** capability flag. To query for this capability, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps). If the device supports luma keying, it sets the **DXVAHD_FEATURE_CAPS_LUMA_KEY** flag in the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

If the device does not support luma keying, the [IDXVAHD_VideoProcessor::SetVideoProcessStreamState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessstreamstate) method fails for this state.

If the input format is RGB, the device must also support the **DXVAHD_INPUT_FORMAT_CAPS_RGB_LUMA_KEY** capability. This capability flag is set in the **InputFormatCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure. If the flag is not present, the device ignores the luma key value for RGB input.

The values of **Lower** and **Upper** give the lower and upper bounds of the luma key, using a nominal range of [0...1]. Given a format with *n* bits per channel, these values are converted to luma values as follows:

`val = f * ((1 << n)-1)`

Any pixel whose luma value falls within the upper and lower bounds (inclusive) is treated as transparent.

For example, if the pixel format uses 8-bit luma, the upper bound is calculated as follows:

`BYTE Y = BYTE(max(min(1.0, Upper), 0.0) * 255.0)`

Note that the value is clamped to the range [0...1] before multiplying by 255.

#### Examples

```cpp
HRESULT DXVAHD_SetLumaKey(
    IDXVAHD_VideoProcessor *pVP,
    UINT stream,
    BOOL bEnable,
    float fLower,   // Lower bound for the luma key.
    float fUpper    // Upper bound for the luma key.
    )
{
    DXVAHD_STREAM_STATE_LUMA_KEY_DATA luma = { bEnable, fLower, fUpper };

    HRESULT hr = pVP->SetVideoProcessStreamState(
        stream,
        DXVAHD_STREAM_STATE_LUMA_KEY,
        sizeof(luma),
        &luma
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