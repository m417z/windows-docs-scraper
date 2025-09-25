# D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS enumeration

## Description

Specifies the inverse telecine (IVTC) capabilities of a video processor.

## Constants

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_32:0x1`

The video processor can reverse 3:2 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_22:0x2`

The video processor can reverse 2:2 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_2224:0x4`

The video processor can reverse 2:2:2:4 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_2332:0x8`

The video processor can reverse 2:3:3:2 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_32322:0x10`

The video processor can reverse 3:2:3:2:2 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_55:0x20`

The video processor can reverse 5:5 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_64:0x40`

The video processor can reverse 6:4 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_87:0x80`

The video processor can reverse 8:7 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_222222222223:0x100`

The video processor can reverse 2:2:2:2:2:2:2:2:2:2:2:3 pulldown.

### `D3D11_VIDEO_PROCESSOR_ITELECINE_CAPS_OTHER:0x80000000`

The video processor can reverse other telecine modes not listed here.

## See also

[D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_processor_rate_conversion_caps)

[Direct3D 11 Video Enumerations](https://learn.microsoft.com/windows/desktop/medfound/direct3d-11-video-enumerations)