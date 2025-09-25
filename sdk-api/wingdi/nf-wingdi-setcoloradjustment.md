# SetColorAdjustment function

## Description

The **SetColorAdjustment** function sets the color adjustment values for a device context (DC) using the specified values.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpca` [in]

A pointer to a [COLORADJUSTMENT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-coloradjustment) structure containing the color adjustment values.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The color adjustment values are used to adjust the input color of the source bitmap for calls to the [StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt) and [StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits) functions when HALFTONE mode is set.

## See also

[COLORADJUSTMENT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-coloradjustment)

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetColorAdjustment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getcoloradjustment)

[SetStretchBltMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setstretchbltmode)

[StretchBlt](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchblt)

[StretchDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-stretchdibits)