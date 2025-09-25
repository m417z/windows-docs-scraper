# DAD_DragMove function

## Description

[**DAD_DragMove** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions. Use [ImageList_DragMove](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragmove) instead.
]

Moves the image that is being dragged during a drag-and-drop operation.

## Parameters

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The coordinates at which to display the drag image. The coordinates are relative to the upper-left corner of the window, not the client area.

## Return value

Type: **BOOL**

Returns nonzero if successful, or zero otherwise.