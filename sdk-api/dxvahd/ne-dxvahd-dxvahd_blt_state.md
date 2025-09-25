# DXVAHD_BLT_STATE enumeration

## Description

Specifies state parameters for blit operations when using Microsoft DirectX Video Acceleration High Definition (DXVA-HD).

To set a state parameter, call the [IDXVAHD_VideoProcessor::SetVideoProcessBltState](https://learn.microsoft.com/windows/desktop/api/dxvahd/nf-dxvahd-idxvahd_videoprocessor-setvideoprocessbltstate) method. This method takes a **DXVAHD_BLT_STATE** value and a byte array as input. The byte array contains state data, the structure of which is defined by the **DXVAHD_BLT_STATE** value.

## Constants

### `DXVAHD_BLT_STATE_TARGET_RECT:0`

Specifies the target rectangle, which is the area within the destination surface where the output will be drawn. The state data is a [DXVAHD_BLT_STATE_TARGET_RECT_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_target_rect_data) structure.

### `DXVAHD_BLT_STATE_BACKGROUND_COLOR:1`

Specifies the background color. The state data is a [DXVAHD_BLT_STATE_BACKGROUND_COLOR_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_blt_state_background_color_data) structure.

### `DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE:2`

Specifies the output color space. The state data is a [DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA](https://learn.microsoft.com/windows/win32/api/dxvahd/ns-dxvahd-dxvahd_blt_state_output_color_space_data) structure.

### `DXVAHD_BLT_STATE_ALPHA_FILL:3`

Specifies how DXVA-HD device calculates output alpha values. The state data is a [DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data) structure.

### `DXVAHD_BLT_STATE_CONSTRICTION:4`

Specifies the amount of downsampling to perform on the output. The state data is a [DXVAHD_BLT_STATE_CONSTRICTION_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_constriction_data) structure.

### `DXVAHD_BLT_STATE_PRIVATE:1000`

Specifies that the state data contains a private DXVA-HD blit state. Use this state for proprietary or device-specific parameters. The state data is a [DXVAHD_BLT_STATE_PRIVATE_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_private_data) structure.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)