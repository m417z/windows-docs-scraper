## Description

Retrieves the scan line that is currently being drawn on the monitor.

## Parameters

### `unnamedParam1` [out]

A pointer to a variable that receives the scan line that the display is currently drawing.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_UNSUPPORTED
* DDERR_VERTICALBLANKINPROGRESS

## Remarks

Scan lines are reported as zero-based integers. The returned scan line value is in the range from 0 through n, where 0 is the first visible scan line on the screen and n is the last visible scan line, plus any scan lines that occur during the vertical blank period. So, in a case where an application is running at a resolution of 640×480 and there are 12 scan lines during vblank, the values returned by this method range from 0 through 491.

## See also

[IDirectDraw7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdraw7)