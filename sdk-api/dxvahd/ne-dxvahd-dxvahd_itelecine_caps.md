# DXVAHD_ITELECINE_CAPS enumeration

## Description

Specifies the inverse telecine (IVTC) capabilities of a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) video processor.

## Constants

### `DXVAHD_ITELECINE_CAPS_32:0x1`

The video processor can reverse 3:2 pulldown.

### `DXVAHD_ITELECINE_CAPS_22:0x2`

The video processor can reverse 2:2 pulldown.

### `DXVAHD_ITELECINE_CAPS_2224:0x4`

The video processor can reverse 2:2:2:4 pulldown.

### `DXVAHD_ITELECINE_CAPS_2332:0x8`

The video processor can reverse 2:3:3:2 pulldown.

### `DXVAHD_ITELECINE_CAPS_32322:0x10`

The video processor can reverse 3:2:3:2:2 pulldown.

### `DXVAHD_ITELECINE_CAPS_55:0x20`

The video processor can reverse 5:5 pulldown.

### `DXVAHD_ITELECINE_CAPS_64:0x40`

The video processor can reverse 6:4 pulldown.

### `DXVAHD_ITELECINE_CAPS_87:0x80`

The video processor can reverse 8:7 pulldown.

### `DXVAHD_ITELECINE_CAPS_222222222223:0x100`

The video processor can reverse 2:2:2:2:2:2:2:2:2:2:2:3 pulldown.

### `DXVAHD_ITELECINE_CAPS_OTHER:0x80000000`

The video processor can reverse other telecine modes not listed here.

## See also

[DXVA-HD](https://learn.microsoft.com/windows/desktop/medfound/dxva-hd)

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-enumerations)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)