# _DXVA_VideoTransferFunction enumeration

## Description

The DXVA_VideoTransferFunction enumeration type contains enumerators that identify the conversion function from R'G'B' to RGB.

## Constants

### `DXVA_VideoTransFuncShift`

Specifies to shift bits by 27 positions (DXVA_ExtColorData_ShiftBase + 19, or 8 + 19).

### `DXVA_VideoTransFuncMask`

Specifies the video transfer function mask. 5 (0xF8000000) bits of a DWORD can be used to specify the video transfer function.

### `DXVA_VideoTransFunc_Unknown`

Specifies that the video transfer function is not specified. The default is 22_8bit_sRGB if required for a computation.

### `DXVA_VideoTransFunc_10`

Specifies linear RGB conversion (corresponds to gamma = 1.0).

### `DXVA_VideoTransFunc_18`

Specifies true 1.8 gamma. That is, L' = pow(L, 1/gamma) for L=0..1.

### `DXVA_VideoTransFunc_20`

Specifies true 2.0 gamma. That is, L' = pow(L, 1/gamma) for L=0..1.

### `DXVA_VideoTransFunc_22`

### `DXVA_VideoTransFunc_22_709`

### `DXVA_VideoTransFunc_22_240M`

### `DXVA_VideoTransFunc_22_8bit_sRGB`

Specifies gamma 2.4 curve with a linear range in the low range, which makes it match an accurate 2.2 gamma 8 bit curve.

### `DXVA_VideoTransFunc_28`

Specifies true 2.8 gamma. That is, L' = pow(L, 1/gamma) for L=0..1.

## Remarks

One of the enumerators of DXVA_VideoTransferFunction can be specified in the **VideoTransferFunction** member of the [DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat) structure.

DXVA_VideoTransferFunction corresponds to the gamma function of the data. Some transfer functions have corrections to account for 8 bit integer quantization effects.

## See also

[DXVA_ExtendedFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxva/ns-dxva-_dxva_extendedformat)