# GetColorAdjustment function

## Description

The **GetColorAdjustment** function retrieves the color adjustment values for the specified device context (DC).

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpca` [out]

A pointer to a [COLORADJUSTMENT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-coloradjustment) structure that receives the color adjustment values.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[COLORADJUSTMENT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-coloradjustment)

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[SetColorAdjustment](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setcoloradjustment)