# ColorAdjustLuma function

## Description

Changes the luminance of a RGB value. Hue and saturation are not affected.

## Parameters

### `clrRGB`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

The initial RGB value.

### `n`

Type: **int**

The luminance in units of 0.1 percent of the total range. For example, a value of *n* = 50 corresponds to 5 percent of the maximum luminance.

### `fScale`

Type: **BOOL**

If *fScale* is set to **TRUE**, *n* specifies how much to increment or decrement the current luminance. If *fScale* is set to **FALSE**, *n* specifies the absolute luminance.

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

Returns the modified RGB value.

## Remarks

If *fScale* is set to **TRUE**, *n* can range from -1000 to +1000.

If *fScale* is set to **FALSE**, *n* can range from 0 to 1000. Available luminance values range from 0 to a maximum. If the requested value is negative or exceeds the maximum, the luminance will be set to either zero or the maximum value, respectively.