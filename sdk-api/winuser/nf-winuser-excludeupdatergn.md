# ExcludeUpdateRgn function

## Description

The **ExcludeUpdateRgn** function prevents drawing within invalid areas of a window by excluding an updated region in the window from a clipping region.

## Parameters

### `hDC` [in]

Handle to the device context associated with the clipping region.

### `hWnd` [in]

Handle to the window to update.

## Return value

The return value specifies the complexity of the excluded region; it can be any one of the following values.

| Value | Meaning |
| --- | --- |
| COMPLEXREGION | Region consists of more than one rectangle. |
| ERROR | An error occurred. |
| NULLREGION | Region is empty. |
| SIMPLEREGION | Region is a single rectangle. |

## See also

[BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint)

[GetUpdateRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdaterect)

[GetUpdateRgn](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getupdatergn)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)

[UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow)