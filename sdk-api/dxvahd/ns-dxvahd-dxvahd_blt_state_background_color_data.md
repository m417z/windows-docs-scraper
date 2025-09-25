# DXVAHD_BLT_STATE_BACKGROUND_COLOR_DATA structure

## Description

Specifies the background color for blit operations, when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

## Members

### `YCbCr`

If **TRUE**, the **BackgroundColor** member specifies a YCbCr color. Otherwise, it specifies an RGB color. The default device state is **FALSE** (RGB color).

### `BackgroundColor`

A [DXVAHD_COLOR](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_color) union that specifies the background color. The default state value is (0.0, 0.0, 0.0, 1.0).

## Remarks

The background color is used to fill the target rectangle wherever no video image appears. Areas outside the target rectangle are not affected. See [DXVAHD_BLT_STATE_TARGET_RECT_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_target_rect_data).

The color space of the background color is determined by the color space of the output. See [DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_blt_state_output_color_space_data).

The alpha value of the background color is used only when the alpha fill mode is **DXVAHD_ALPHA_FILL_MODE_BACKGROUND**. Otherwise, the alpha value is ignored. See [DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data).

The default background color is full-range RGB black, with opaque alpha.

#### Examples

```cpp
HRESULT DXVAHD_SetBackgroundColor(
    IDXVAHD_VideoProcessor *pVP,
    BOOL bYCbCr,
    const DXVAHD_COLOR& color
    )
{
    DXVAHD_BLT_STATE_BACKGROUND_COLOR_DATA data = { bYCbCr, color };

    HRESULT hr = pVP->SetVideoProcessBltState(
        DXVAHD_BLT_STATE_BACKGROUND_COLOR,
        sizeof (data),
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