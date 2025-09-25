# MFVideoTransferMatrix enumeration

## Description

Describes the conversion matrices between Y'PbPr (component video) and studio R'G'B'.

## Constants

### `MFVideoTransferMatrix_Unknown:0`

Unknown transfer matrix. Treat as MFVideoTransferMatrix_BT709.

### `MFVideoTransferMatrix_BT709:1`

ITU-R BT.709 transfer matrix.

### `MFVideoTransferMatrix_BT601:2`

ITU-R BT.601 transfer matrix. Also used for SMPTE 170 and ITU-R BT.470-2 System B,G.

### `MFVideoTransferMatrix_SMPTE240M:3`

SMPTE 240M transfer matrix.

### `MFVideoTransferMatrix_BT2020_10:4`

BT.2020 non-constant luminance.

### `MFVideoTransferMatrix_BT2020_12:5`

BT.2020 non-constant luminance.

### `MFVideoTransferMatrix_Identity:6`

Identity. IEC 61966-2-1 (sRGB), SMPTE ST.428-1.

### `MFVideoTransferMatrix_FCC47:7`

FCC Title 47. The exact formula is defined in ISO/IEC 23091-2.

### `MFVideoTransferMatrix_YCgCo:8`

YCbCr pixels are actually YCoCg pixels. The matrix to convert such pixels to RGB is defined in ISO/IEC 23091-2.

### `MFVideoTransferMatrix_SMPTE2085:9`

The matrix defined for High Dynamic Range (HDR) video, defined by [SMPTE ST 2085](https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=7395514).

### `MFVideoTransferMatrix_Chroma:10`

Chromacity-derived non-constant luminance system, as defined in IEC 23091-2.

### `MFVideoTransferMatrix_Chroma_const:11`

Chromacity-derived constant luminance system, as defined in IEC 23091-2.

### `MFVideoTransferMatrix_ICtCp:12`

High Dynamic Range (HDR) and Wide Color Gamut video, as defined by ITU-R BT.2100. The transfer matrix is available in ISO/IEC 23091-2 and is also commonly known as [ICtCp](https://en.wikipedia.org/wiki/ICtCp).

### `MFVideoTransferMatrix_Last`

Reserved.

### `MFVideoTransferMatrix_ForceDWORD:0x7fffffff`

Reserved. This member forces the enumeration type to compile as a **DWORD** value.

## Remarks

This enumeration is used with the [MF_MT_YUV_MATRIX](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-yuv-matrix-attribute) attribute.

For more information about these values, see the remarks for the [DXVA2_VideoTransferMatrix](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_videotransfermatrix) enumeration, which is the DirectX Video Acceleration (DXVA) equivalent of this enumeration.

## See also

[Extended Color Information](https://learn.microsoft.com/windows/desktop/medfound/extended-color-information)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)