# DXVA2_VideoTransferFunction enumeration

## Description

Specifies the conversion function from linear RGB to non-linear RGB (R'G'B'). These flags are used in the DXVA2_ExtendedFormat Structure.

## Constants

### `DXVA2_VideoTransFuncMask:0x1f`

Bitmask to validate flag values. This value is not a valid flag.

### `DXVA2_VideoTransFunc_Unknown:0`

Unknown. Treat as DXVA2_VideoTransFunc_709.

### `DXVA2_VideoTransFunc_10:1`

Linear RGB (gamma = 1.0).

### `DXVA2_VideoTransFunc_18:2`

True 1.8 gamma, L' = L^1/1.8.

### `DXVA2_VideoTransFunc_20:3`

True 2.0 gamma, L' = L^1/2.0.

### `DXVA2_VideoTransFunc_22:4`

True 2.2 gamma, L' = L^1/2.2. This transfer function is used in ITU-R BT.470-2 System M (NTSC).

### `DXVA2_VideoTransFunc_709:5`

ITU-R BT.709 transfer function. Gamma 2.2 curve with a linear segment in the lower range. This transfer function is used in BT.709, BT.601, SMPTE 296M, SMPTE 170M, BT.470, and SMPTE 274M. In addition BT-1361 uses this function within the range [0...1].

### `DXVA2_VideoTransFunc_240M:6`

SMPTE 240M transfer function. Gamma 2.2 curve with a linear segment in the lower range.

### `DXVA2_VideoTransFunc_sRGB:7`

sRGB transfer function. Gamma 2.4 curve with a linear segment in the lower range.

### `DXVA2_VideoTransFunc_28:8`

True 2.8 gamma. L' = L^1/2.8. This transfer function is used in ITU-R BT.470-2 System B, G (PAL).

## Remarks

The following table shows the formulas for the most common transfer functions. In these formulas, L is the linear value and L' is the non-linear (gamma corrected) value. These values are relative to a normalized range [0...1].

| Color space | Transfer function |
| --- | --- |
| sRGB (8-bit) | L' = 12.92L, for L < 0.031308<br><br>L' = 1.055L^1/2.4− 0.055, for L >= 0.031308 |
| BT.470-2 System B, G | L' = L^0.36 |
| BT.470-2 System M | L' = L^0.45 |
| BT.709 | L' = 4.50L, for L < 0.018<br><br>L' = 1.099L^0.45− 0.099, for L >= 0.018 |
| scRGB | L' = L |
| SMPTE 240M | L' = 4.0L, for L < 0.0228<br><br>L' = 1.1115L^0.45− 0.01115, for L >= 0.0228 |

The following table shows the inverse formulas to obtain the original gamma-corrected values:

| Color space | Transfer function |
| --- | --- |
| sRGB (8-bit) | L = 1/12.92L', for L' < 0.03928<br><br>L = ((L' + 0.055)/1055)^2.4, for L' >= 0.03928 |
| BT.470-2 System B, G | L = L'^1/0.36 |
| BT.470-2 System M | L = L'^1/0.45 |
| BT.709 | L = L'/4.50, for L' < 0.081<br><br>L = ((L' + 0.099) / 1.099)^1/0.45, for L' >= 0.081 |
| scRGB | L = L' |
| SMPTE 240M | L = L'/4.0, for L' < 0.0913<br><br>L= ((L' + 0.1115)/1.1115)^1/0.45, for L' >= 0.0913 |

This enumeration is equivalent to the **DXVA_VideoTransferFunction** enumeration used in DXVA 1.0.

If you are using the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface to describe the video format, the transfer function is specified in the [MF_MT_TRANSFER_FUNCTION](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-transfer-function-attribute) attribute.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)