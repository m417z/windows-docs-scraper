# DrawDibRealize function

## Description

The **DrawDibRealize** function realizes the palette of the DrawDib DC for use with the specified DC.

## Parameters

### `hdd`

Handle to a DrawDib DC.

### `hdc`

Handle to the DC containing the palette.

### `fBackground`

Background palette flag. If this value is nonzero, the palette is a background palette. If this value is zero and the DC is attached to a window, the logical palette becomes the foreground palette when the window has the input focus. (A DC is attached to a window when the window class style is CS_OWNDC or when the DC is obtained by using the [GetDC](https://learn.microsoft.com/previous-versions//ms533241(v=vs.85)) function.)

## Return value

Returns the number of entries in the logical palette mapped to different values in the system palette. If an error occurs or no colors were updated, it returns zero.

## Remarks

To select the palette of the DrawDib DC as a background palette, use the [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw) function and specify the DDF_BACKGROUNDPAL flag.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)