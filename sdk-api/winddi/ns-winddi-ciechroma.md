# CIECHROMA structure

## Description

The CIECHROMA structure is used to describe the chromaticity coordinates, **x** and **y**, and the luminance, **Y** in CIE color space.

## Members

### `x`

Specifies the x-coordinate in CIE chromaticity space.

### `y`

Specifies the y-coordinate in CIE chromaticity space.

### `Y`

Specifies the luminance. For more information, see the following Remarks section.

## Remarks

The CIECHROMA structure is used by the [COLORINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-colorinfo) structure to define colors for [GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo).

The LDECI4 type is used to represent real numbers to four decimal places. For example, (LDECI4) 10000 represents the real number 1.0000, and (LDECI4) -12345 represents -1.2345.

The values of the **x** and **y** members of CIECHROMA should be in the range from 0 through 10000--that is, the values should represent the numbers 0.0000 through 1.0000.

The value of the **Y** member of this structure should be in the range from 0 through 100. This member can also be 65534 (0xFFFE) under certain circumstances. For more information about these circumstances, see [COLORINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-colorinfo).

## See also

[COLORINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-colorinfo)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[GDIINFO](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-gdiinfo)