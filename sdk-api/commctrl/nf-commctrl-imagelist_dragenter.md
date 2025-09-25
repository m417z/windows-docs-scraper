# ImageList_DragEnter function

## Description

Displays the drag image at the specified position within the window.

## Parameters

### `hwndLock`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the window that owns the drag image.

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