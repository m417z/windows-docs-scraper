# ColorCorrectPalette function

## Description

The **ColorCorrectPalette** function corrects the entries of a palette using the WCS 1.0 parameters in the specified device context.

## Parameters

### `hdc`

Specifies a device context whose WCS parameters to use.

### `hPal`

Specifies the handle to the palette to be color corrected.

### `deFirst`

Specifies the first entry in the palette to be color corrected.

### `num`

Specifies the number of entries to color correct.

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)