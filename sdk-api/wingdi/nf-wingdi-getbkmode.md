# GetBkMode function

## Description

The **GetBkMode** function returns the current background mix mode for a specified device context. The background mix mode of a device context affects text, hatched brushes, and pen styles that are not solid lines.

## Parameters

### `hdc` [in]

Handle to the device context whose background mode is to be returned.

## Return value

If the function succeeds, the return value specifies the current background mix mode, either OPAQUE or TRANSPARENT.

If the function fails, the return value is zero.

## See also

[GetBkColor](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbkcolor)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[SetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setbkmode)