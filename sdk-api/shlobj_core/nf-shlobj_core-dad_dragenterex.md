# DAD_DragEnterEx function

## Description

[**DAD_DragEnterEx** is available in Windows 2000 and Windows XP. It might be altered or unavailable in subsequent versions. Use [ImageList_DragEnter](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-imagelist_dragenter) instead.
]

Locks updates to the specified window during a drag operation and displays the drag image at the specified position within the window.

## Parameters

### `hwndTarget`

Type: **HWND**

A handle to the window that owns the drag image.

### `ptStart`

Type: **const [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The coordinates at which to begin displaying the drag image. The coordinates are relative to the upper-left corner of the window, not the client area.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, or **FALSE** otherwise.