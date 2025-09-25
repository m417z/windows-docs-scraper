# MFVideoTransferFunction enumeration

## Description

Specifies the conversion function from linear RGB to non-linear RGB (R'G'B').

## Constants

### `MFVideoTransFunc_Unknown:0`

Unknown. Treat as MFVideoTransFunc_709.

### `MFVideoTransFunc_10:1`

Linear RGB (gamma = 1.0).

### `MFVideoTransFunc_18:2`

True 1.8 gamma, L' = L^1/1.8.

### `MFVideoTransFunc_20:3`

True 2.0 gamma, L' = L^1/2.0.

### `MFVideoTransFunc_22:4`

True 2.2 gamma, L' = L^1/2.2. This transfer function is used in ITU-R BT.470-2 System M (NTSC).

### `MFVideoTransFunc_709:5`

ITU-R BT.709 transfer function. Gamma 2.2 curve with a linear segment in the lower range. This transfer function is used in BT.709, BT.601, SMPTE 296M, SMPTE 170M, BT.470, and SPMTE 274M. In addition BT-1361 uses this function within the range [0...1].

### `MFVideoTransFunc_240M:6`

SPMTE 240M transfer function. Gamma 2.2 curve with a linear segment in the lower range.

### `MFVideoTransFunc_sRGB:7`

sRGB transfer function. Gamma 2.4 curve with a linear segment in the lower range.

### `MFVideoTransFunc_28:8`

True 2.8 gamma. L' = L^1/2.8. This transfer function is used in ITU-R BT.470-2 System B, G (PAL).

### `MFVideoTransFunc_Log_100:9`

Logarithmic transfer (100:1 range); for example, as used in H.264 video.

**Note** Requires Windows 7 or later.

### `MFVideoTransFunc_Log_316:10`

Logarithmic transfer (316.22777:1 range); for example, as used in H.264 video.

**Note** Requires Windows 7 or later.

### `MFVideoTransFunc_709_sym:11`

Symmetric ITU-R BT.709.

**Note** Requires Windows 7 or later.

### `MFVideoTransFunc_2020_const:12`

Constant luminance ITU-R BT.2020. See [Recommendation ITU-R BT.2020-2](https://www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.2020-2-201510-I!!PDF-E.pdf).

**Note** Requires Windows 8 or later.

### `MFVideoTransFunc_2020:13`

Non-constant luminance ITU-R BT.2020. See [Recommendation ITU-R BT.2020-2](https://www.itu.int/dms_pubrec/itu-r/rec/bt/R-REC-BT.2020-2-201510-I!!PDF-E.pdf).

**Note** Requires Windows 8 or later.

### `MFVideoTransFunc_26:14`

True 2.6 gamma, L’=L^1/2.6

**Note** Requires Windows 8 or later.

### `MFVideoTransFunc_2084:15`

SMPTE ST.2084 also known as PQ. Also defined in ITU-R BT.2100

**Note** Requires Windows 10, version 1703 or later.

### `MFVideoTransFunc_HLG:16`

Hybrid Log-Gamma, ARIB STD-B67

**Note** Requires Windows 10, version 1703 or later.

### `MFVideoTransFunc_10_rel:17`

No gamma, display referred (relative).

### `MFVideoTransFunc_BT1361_ECG:18`

The transfer function Extended Color Gamut video, as defined by ITU-R BT.1361.

### `MFVideoTransFunc_SMPTE428:19`

Video transfer function defined in [SMPTE ST 428-1](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7290876).

### `MFVideoTransFunc_Last`

Reserved.

### `MFVideoTransFunc_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

These flags are used with the [MF_MT_TRANSFER_FUNCTION](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-transfer-function-attribute) attribute.

For more information about these values, see the remarks for the [DXVA2_VideoTransferFunction](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videotransferfunction) enumeration, which is the DirectX Video Acceleration (DXVA) equivalent of this enumeration.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)