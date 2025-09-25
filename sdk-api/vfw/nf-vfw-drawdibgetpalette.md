# DrawDibGetPalette function

## Description

The **DrawDibGetPalette** function retrieves the palette used by a DrawDib DC.

## Parameters

### `hdd`

Handle to a DrawDib DC.

## Return value

Returns a handle to the palette if successful or **NULL** otherwise.

## Remarks

This function assumes the DrawDib DC contains a valid palette entry, implying that a call to this function must follow calls to the [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw) or [DrawDibBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibbegin) functions.

You should rarely need to call this function because you can realize the correct palette in response to a window message by using the [DrawDibRealize](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibrealize) function.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)