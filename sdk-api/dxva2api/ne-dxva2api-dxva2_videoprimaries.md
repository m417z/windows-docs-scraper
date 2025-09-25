# DXVA2_VideoPrimaries enumeration

## Description

Specifies the color primaries of a video source. These flags are used in the [DXVA2_ExtendedFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_extendedformat) structure.

## Constants

### `DXVA2_VideoPrimariesMask:0x1f`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_VideoPrimaries_Unknown:0`

Unknown. Treat as **DXVA2_VideoPrimaries_BT709**.

### `DXVA2_VideoPrimaries_reserved:1`

Reserved. Do not use.

### `DXVA2_VideoPrimaries_BT709:2`

ITU-R BT.709. Also used for sRGB and scRGB.

### `DXVA2_VideoPrimaries_BT470_2_SysM:3`

ITU-R BT.470-4 System M (NTSC).

### `DXVA2_VideoPrimaries_BT470_2_SysBG:4`

ITU-R BT.470-4 System B,G (PAL).

### `DXVA2_VideoPrimaries_SMPTE170M:5`

SMPTE 170M.

### `DXVA2_VideoPrimaries_SMPTE240M:6`

SMPTE 240M.

### `DXVA2_VideoPrimaries_EBU3213:7`

EBU Tech. 3213.

### `DXVA2_VideoPrimaries_SMPTE_C:8`

SMPTE C (SMPTE RP 145).

## Remarks

Color primaries define how to convert RGB colors into the CIE XYZ color space, and can be used to translate colors between different RGB color spaces. An RGB color space is defined by the chromaticity coordinates (x,y) of the RGB primaries plus the white point, as listed in the following table.

| Color space | (Rx, Ry) | (Gx, Gy) | (Bx, By) | White point (Wx, Wy) |
| --- | --- | --- | --- | --- |
| BT.709 | (0.64, 0.33) | (0.30, 0.60) | (0.15, 0.06) | D65 (0.3127, 0.3290) |
| BT.470-2 System B,G; EBU 3213 | (0.64, 0.33) | (0.29, 0.60) | (0.15, 0.06) | D65 (0.3127, 0.3290) |
| BT.470-4 System M | (0.67, 0.33) | (0.21, 0.71) | (0.14, 0.08) | CIE III.C (0.310, 0.316) |
| SMPTE 170M; SMPTE 240M; SMPTE C | (0.63, 0.34) | (0.31, 0.595) | (0.155, 0.07) | D65 (0.3127, 0.3291) |

The z coordinates can be derived from x and y as follows: z = 1 - x - y. To convert between RGB colors to CIE XYZ tristimulus values, compute a matrix *T* as follows:

![Screenshot of a matrix computation, showing an RGB conversion.](https://learn.microsoft.com/windows/win32/api/dxva2api/images/6b28e3fc-d85b-4cd2-a535-522ac9f11501.gif)
Given *T*, you can use the following formulas to convert between an RGB color value and a CIE XYZ tristimulus value. These formulas assume that the RGB components are linear (not gamma corrected) and are normalized to the range [0...1].

![Screenshot of a matrix computation, showing a conversion between an RGB color value and a CIE XYZ tristimulus value.](https://learn.microsoft.com/windows/win32/api/dxva2api/images/5e0b7470-4123-49f4-93ed-be9955ccf825.gif)
To convert colors directly from one RGB color space to another, use the following formula, where *T1* is the matrix for color space RGB1, and *T2* is the matrix for color space RGB2.

![Screenshot of a matrix computation, showing a conversion of one RGB color space to another.](https://learn.microsoft.com/windows/win32/api/dxva2api/images/3c2f9626-ef5e-4165-a24e-8720e215ef13.gif)
For a derivation of these formulas, refer to Charles Poynton, Digital Video and HDTV Algorithms and Interfaces (Morgan Kaufmann, 2003).

This enumeration is equivalent to the **DXVA_VideoPrimaries** enumeration used in DXVA 1.0.

If you are using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface to describe the video format, the color primaries are specified in the [MF_MT_VIDEO_PRIMARIES](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-video-primaries-attribute) attribute.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)