# DXVAHD_ALPHA_FILL_MODE enumeration

## Description

Specifies how the output alpha values are calculated for Microsoft DirectX Video Acceleration High Definition (DXVA-HD) blit operations.

## Constants

### `DXVAHD_ALPHA_FILL_MODE_OPAQUE:0`

Alpha values inside the target rectangle are set to opaque.

### `DXVAHD_ALPHA_FILL_MODE_BACKGROUND:1`

Alpha values inside the target rectangle are set to the alpha value specified in the background color. See [DXVAHD_BLT_STATE_BACKGROUND_COLOR](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_blt_state_background_color_data).

### `DXVAHD_ALPHA_FILL_MODE_DESTINATION:2`

Existing alpha values remain unchanged in the output surface.

### `DXVAHD_ALPHA_FILL_MODE_SOURCE_STREAM:3`

Alpha values from the input stream are scaled and copied to the corresponding destination rectangle for that stream. If the input stream does not have alpha data, the DXVA-HD device sets the alpha values in the target rectangle to an opaque value. If the input stream is disabled or the source rectangle is empty, the alpha values in the target rectangle are not modified.

## Remarks

The **Mode** member of the [DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data) structure has this enumeration type. That member specifies the alpha-fill mode for the input stream identified by the **StreamNumber** member of the same structure. To set the alpha-fill mode, call [IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate).

To find out which modes the device supports, call the [IDXVAHD_Device::GetVideoProcessorDeviceCaps](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_device-getvideoprocessordevicecaps) method. If the device sets the **DXVAHD_FEATURE_CAPS_ALPHA_FILL** flag in the **FeatureCaps** member of the [DXVAHD_VPDEVCAPS](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_vpdevcaps) structure, the DXVA-HD device supports any of the modes listed here. Otherwise, the alpha-fill mode must be **DXVAHD_ALPHA_FILL_MODE_OPAQUE**.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)