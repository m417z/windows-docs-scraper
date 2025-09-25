# DXVA2_Fixed32 structure

## Description

Defines a 32-bit fixed-point number.

## Members

### `Fraction`

Fractional part of the number.

### `Value`

Integer part of the number.

### `ll`

Accesses the entire 32 bits of the number. You can use this member to compare **DXVA2_Fixed32** values.

## Remarks

To convert between floating-point numbers and **DXVA2_Fixed32** values, use the [DXVA2FixedToFloat](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-dxva2fixedtofloat) and [DXVA2FloatToFixed](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-dxva2floattofixed) functions.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)