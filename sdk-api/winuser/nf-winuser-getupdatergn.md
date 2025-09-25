# GetUpdateRgn function

## Description

The **GetUpdateRgn** function retrieves the update region of a window by copying it into the specified region. The coordinates of the update region are relative to the upper-left corner of the window (that is, they are client coordinates).

## Parameters

### `hWnd` [in]

Handle to the window with an update region that is to be retrieved.

### `hRgn` [in]

Handle to the region to receive the update region.

### `bErase` [in]

Specifies whether the window background should be erased and whether nonclient areas of child windows should be drawn. If this parameter is **FALSE**, no drawing is done.

## Return value

The return value indicates the complexity of the resulting region; it can be one of the following values.

| Value | Meaning |
| --- | --- |
| COMPLEXREGION | Region consists of more than one rectangle. |
| ERROR | An error occurred. |
| NULLREGION | Region is empty. |
| SIMPLEREGION | Region is a single rectangle. |

## Remarks

The [BeginPaint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-beginpaint) function automatically validates the update region, so any call to **GetUpdateRgn** made immediately after the call to **BeginPaint** retrieves an empty update region.

## See also

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)