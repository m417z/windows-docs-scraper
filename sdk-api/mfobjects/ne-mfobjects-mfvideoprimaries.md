# MFVideoPrimaries enumeration

## Description

Specifies the color primaries of a video source. The color primaries define how to convert colors from RGB color space to CIE XYZ color space.

## Constants

### `MFVideoPrimaries_Unknown:0`

The color primaries are unknown.

### `MFVideoPrimaries_reserved:1`

Reserved.

### `MFVideoPrimaries_BT709:2`

ITU-R BT.709. Also used for sRGB and scRGB.

### `MFVideoPrimaries_BT470_2_SysM:3`

ITU-R BT.470-4 System M (NTSC).

### `MFVideoPrimaries_BT470_2_SysBG:4`

ITU-R BT.470-4 System B,G (NTSC).

### `MFVideoPrimaries_SMPTE170M:5`

SMPTE 170M.

### `MFVideoPrimaries_SMPTE240M:6`

SMPTE 240M.

### `MFVideoPrimaries_EBU3213:7`

EBU 3213.

### `MFVideoPrimaries_SMPTE_C:8`

SMPTE C (SMPTE RP 145).

### `MFVideoPrimaries_BT2020:9`

ITU-R BT.2020 color primaries.

**Note** Requires Windows 8 or later.

### `MFVideoPrimaries_XYZ:10`

CIE 1931 XYZ (see: [CIE 1931 color space](https://en.wikipedia.org/wiki/CIE_1931_color_space)). Note that this color space is only well-defined for floating point representations.

**Note** Requires Windows 8 or later.

### `MFVideoPrimaries_DCI_P3:11`

DCI-P3

**Note** Requires Windows 10, version 1703 or later.

### `MFVideoPrimaries_ACES:12`

Academy Color Encoding System

**Note** Requires Windows 10, version 1703 or later.

### `MFVideoPrimaries_Display_P3:13`

SMPTE EG-432-1 (DCI P3 with D65 white point)

### `MFVideoPrimaries_Last`

Reserved.

### `MFVideoPrimaries_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

This enumeration is used with the [MF_MT_VIDEO_PRIMARIES](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-primaries-attribute) attribute.

For more information about these values, see the remarks for the [DXVA2_VideoPrimaries](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videoprimaries) enumeration, which is the DirectX Video Acceleration (DXVA) equivalent of this enumeration.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)