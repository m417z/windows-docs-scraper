# DXVAHD_FILTER_CAPS enumeration

## Description

Defines capabilities related to image adjustment and filtering for a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Constants

### `DXVAHD_FILTER_CAPS_BRIGHTNESS:0x1`

The device can adjust the brightness level.

### `DXVAHD_FILTER_CAPS_CONTRAST:0x2`

The device can adjust the contrast level.

### `DXVAHD_FILTER_CAPS_HUE:0x4`

The device can adjust hue.

### `DXVAHD_FILTER_CAPS_SATURATION:0x8`

The device can adjust the saturation level.

### `DXVAHD_FILTER_CAPS_NOISE_REDUCTION:0x10`

The device can perform noise reduction.

### `DXVAHD_FILTER_CAPS_EDGE_ENHANCEMENT:0x20`

The device can perform edge enhancement.

### `DXVAHD_FILTER_CAPS_ANAMORPHIC_SCALING:0x40`

The device can perform *anamorphic scaling*. Anamorphic scaling can be used to stretch 4:3 content to a widescreen 16:9 aspect ratio.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)