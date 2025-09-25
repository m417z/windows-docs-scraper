# DISPLAYCONFIG_PIXELFORMAT enumeration

## Description

The DISPLAYCONFIG_PIXELFORMAT enumeration specifies pixel format in various bits per pixel (BPP) values.

## Constants

### `DISPLAYCONFIG_PIXELFORMAT_8BPP:1`

Indicates 8 BPP format.

### `DISPLAYCONFIG_PIXELFORMAT_16BPP:2`

Indicates 16 BPP format.

### `DISPLAYCONFIG_PIXELFORMAT_24BPP:3`

Indicates 24 BPP format.

### `DISPLAYCONFIG_PIXELFORMAT_32BPP:4`

Indicates 32 BPP format.

### `DISPLAYCONFIG_PIXELFORMAT_NONGDI:5`

Indicates that the current display is not an 8, 16, 24, or 32 BPP GDI desktop mode. For example, a call to the [QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig) function returns DISPLAYCONFIG_PIXELFORMAT_NONGDI if a DirectX application previously set the desktop to A2R10G10B10 format. A call to the [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function fails if any pixel formats for active paths are set to DISPLAYCONFIG_PIXELFORMAT_NONGDI.

### `DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## See also

[QueryDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-querydisplayconfig)

[SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig)