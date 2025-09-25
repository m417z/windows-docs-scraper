# GetBkColor function

## Description

The **GetBkColor** function returns the current background color for the specified device context.

## Parameters

### `hdc` [in]

Handle to the device context whose background color is to be returned.

## Return value

If the function succeeds, the return value is a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value for the current background color.

If the function fails, the return value is CLR_INVALID.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[GetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbkmode)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkcolor)