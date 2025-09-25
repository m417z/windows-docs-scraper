# MFllMulDiv function

## Description

Calculates ((a * b) + d) / c, where each term is a 64-bit signed value.

## Parameters

### `a`

A multiplier.

### `b`

Another multiplier.

### `c`

The divisor.

### `d`

The rounding factor.

## Return value

Returns the result of the calculation. If numeric overflow occurs, the function returns _I64_MAX (positive overflow) or LLONG_MIN (negative overflow). If Mfplat.dll cannot be loaded, the function returns _I64_MAX.

## Remarks

**Note** A previous version of this topic described the parameters incorrectly. The divisor is *c* and the rounding factor is *d*.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)