# DXVAHD_FEATURE_CAPS enumeration

## Description

Defines features that a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device can support.

## Constants

### `DXVAHD_FEATURE_CAPS_ALPHA_FILL:0x1`

The device can set the alpha values on the video output. See [DXVAHD_BLT_STATE_ALPHA_FILL_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_alpha_fill_data).

### `DXVAHD_FEATURE_CAPS_CONSTRICTION:0x2`

The device can downsample the video output. See [DXVAHD_BLT_STATE_CONSTRICTION_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_blt_state_constriction_data).

### `DXVAHD_FEATURE_CAPS_LUMA_KEY:0x4`

The device can perform luma keying. See [DXVAHD_STREAM_STATE_LUMA_KEY_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_luma_key_data).

### `DXVAHD_FEATURE_CAPS_ALPHA_PALETTE:0x8`

The device can apply alpha values from color palette entries. See [DXVAHD_STREAM_STATE_ALPHA_DATA](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_stream_state_alpha_data).

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)