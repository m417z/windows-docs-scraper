# DXVAHD_STREAM_STATE_ALPHA_DATA structure

## Description

Specifies the planar alpha value for an input stream, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `Enable`

**If TRUE**, alpha blending is enabled. Otherwise, alpha blending is disabled. The default state value is **FALSE**.

### `Alpha`

Specifies the planar alpha value as a floating-point number from 0.0 (transparent) to 1.0 (opaque).

If the **Enable** member is **FALSE**, this member is ignored.

## Remarks

For each pixel, the destination color value is computed as follows:

`Cd = Cs * (As * Ap * Ae) + Cd * (1.0 - As * Ap * Ae)`

where

* `Cd` = Color value of the destination pixel.
* `Cs` = Color value of source pixel.
* `As` = Per-pixel source alpha.
* `Ap` = Planar alpha value.
* `Ae` = Palette-entry alpha value, or 1.0 (see Note).

**Note** Palette-entry alpha values apply only to palettized color formats, and only when the device supports the **DXVAHD_FEATURE_CAPS_ALPHA_PALETTE** capability. Otherwise, this factor equals 1.0.

The destination alpha value is computed according to the **DXVAHD_BLT_STATE_ALPHA_FILL** state. For more information, see [DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data).

To get the device capabilities, call [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) and check the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure.

#### Examples

```cpp
HRESULT DXVAHD_SetPlanarAlpha(
    IDXVAHD_VideoProcessor *pVP,
    UINT stream,
    BOOL bEnable,
    float fAlpha
    )
{
    DXVAHD_STREAM_STATE_ALPHA_DATA alpha = { bEnable, fAlpha };

    HRESULT hr = pVP->SetVideoProcessStreamState(
        stream,
        DXVAHD_STREAM_STATE_ALPHA,
        sizeof(alpha),
        &alpha
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