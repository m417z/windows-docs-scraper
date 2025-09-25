# SaveDC function

## Description

The **SaveDC** function saves the current state of the specified device context (DC) by copying data describing selected objects and graphic modes (such as the bitmap, brush, palette, font, pen, region, drawing mode, and mapping mode) to a context stack.

## Parameters

### `hdc` [in]

A handle to the DC whose state is to be saved.

## Return value

If the function succeeds, the return value identifies the saved state.

If the function fails, the return value is zero.

## Remarks

The **SaveDC** function can be used any number of times to save any number of instances of the DC state.

A saved state can be restored by using the [RestoreDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-restoredc) function.

## See also

[Device Context Functions](https://learn.microsoft.com/windows/desktop/gdi/device-context-functions)

[Device Contexts Overview](https://learn.microsoft.com/windows/desktop/gdi/device-contexts)

[RestoreDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-restoredc)