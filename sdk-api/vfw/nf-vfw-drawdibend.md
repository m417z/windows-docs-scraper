# DrawDibEnd function

## Description

The **DrawDibEnd** function clears the flags and other settings of a DrawDib DC that are set by the [DrawDibBegin](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibbegin) or [DrawDibDraw](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-drawdibdraw) functions.

## Parameters

### `hdd`

Handle to the DrawDib DC to free.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## See also

[DrawDib Functions](https://learn.microsoft.com/windows/desktop/Multimedia/drawdib-functions)