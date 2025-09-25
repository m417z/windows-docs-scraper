# DrawDibChangePalette function

## Description

The **DrawDibChangePalette** function sets the palette entries used for drawing DIBs.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `iStart`

Starting palette entry number.

### `iLen`

Number of palette entries.

### `lppe`

Pointer to an array of palette entries.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

This function changes the physical palette only if the current DrawDib palette is realized by calling the [DrawDibRealize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibrealize) function.

If the color table is not changed, the next call to the [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw) function that does not specify DDF_SAME_DRAW calls the [DrawDibBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibbegin) function implicitly.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)