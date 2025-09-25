# _DXVADDI_VIDEOTRANSFERFUNCTION enumeration

## Description

The DXVADDI_VIDEOTRANSFERFUNCTION enumeration type contains values that identify the conversion function from R'G'B' to RGB.

## Constants

### `DXVADDI_VideoTransFuncMask`

Specifies the video transfer function mask. The first 5 (0x001F) bits of a DWORD can be used to specify the video transfer function.

### `DXVADDI_VideoTransFunc_Unknown`

Specifies that the video transfer function is not specified. The default is 22_8bit_sRGB if required for a computation.

### `DXVADDI_VideoTransFunc_10`

Specifies linear RGB conversion (corresponds to gamma = 1.0).

### `DXVADDI_VideoTransFunc_18`

Specifies true 1.8 gamma--that is, L' = pow(L, 1/gamma) for L=0..1.

### `DXVADDI_VideoTransFunc_20`

Specifies true 2.0 gamma--that is, L' = pow(L, 1/gamma) for L=0..1.

### `DXVADDI_VideoTransFunc_22`

Specifies true 2.2 gamma--that is, L' = pow(L, 1/gamma) for L=0..1.

The BT470-2 SysM primaries (that is, the [DXVADDI_VIDEOPRIMARIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videoprimaries) enumeration type) use gamma 2.2.

### `DXVADDI_VideoTransFunc_709`

Specifies gamma 2.2 curve with a linear range in the low range.

The BT709, SMPTE296M, SMPTE170M, BT470, and SMPTE274M primaries (that is, the DXVADDI_VIDEOPRIMARIES enumeration type) use this video transfer function.

### `DXVADDI_VideoTransFunc_240M`

Specifies gamma 2.2 curve with a linear range in the low range.

The SMPTE240M and interim 274M primaries (that is, the DXVADDI_VIDEOPRIMARIES enumeration type) use this video transfer function.

### `DXVADDI_VideoTransFunc_sRGB`

Specifies gamma 2.4 curve with a linear range in the low range, which makes it match an accurate 2.2 gamma 8-bit curve.

### `DXVADDI_VideoTransFunc_28`

Specifies true 2.8 gamma--that is, L' = pow(L, 1/gamma) for L=0..1.

## Remarks

One of the values of DXVADDI_VIDEOTRANSFERFUNCTION can be specified in the **VideoTransferFunction** member of the [DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat) structure.

DXVADDI_VIDEOTRANSFERFUNCTION corresponds to the gamma function of the data. Some transfer functions have corrections to account for 8-bit integer quantization effects.

The following constants can also be used for gamma function:

```cpp
#define DXVADDI_VideoTransFunc_22_709  DXVADDI_VideoTransFunc_709
#define DXVADDI_VideoTransFunc_22_240M  DXVADDI_VideoTransFunc_240M
#define DXVADDI_VideoTransFunc_22_8bit_sRGB  DXVADDI_VideoTransFunc_sRGB
```

## See also

[DXVADDI_EXTENDEDFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_extendedformat)

[DXVADDI_VIDEOPRIMARIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvaddi_videoprimaries)