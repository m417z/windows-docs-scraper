# ImageList_BeginDrag function

## Description

Begins dragging an image.

## Parameters

### `himlTrack`

Type: **HIMAGELIST**

A handle to the image list.

### `iTrack`

Type: **int**

The index of the image to drag.

### `dxHotspot`

Type: **int**

The x-coordinate of the location of the drag position relative to the upper-left corner of the image.

### `dyHotspot`

Type: **int**

The y-coordinate of the location of the drag position relative to the upper-left corner of the image.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Remarks

This function creates a temporary image list that is used for dragging. In response to subsequent [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) messages, you can move the drag image by using the [ImageList_DragMove](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragmove) function. To end the drag operation, you can use the [ImageList_EndDrag](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_enddrag) function.