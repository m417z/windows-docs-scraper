# ImageList_DragMove function

## Description

Moves the image that is being dragged during a drag-and-drop operation. This function is typically called in response to a [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message.

## Parameters

### `x`

Type: **int**

The x-coordinate at which to display the drag image. The coordinate is relative to the upper-left corner of the window, not the client area.

### `y`

Type: **int**

The y-coordinate at which to display the drag image. The coordinate is relative to the upper-left corner of the window, not the client area.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

To begin a drag operation, use the [ImageList_BeginDrag](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_begindrag) function.