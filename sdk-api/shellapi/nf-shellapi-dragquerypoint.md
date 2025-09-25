# DragQueryPoint function

## Description

Retrieves the position of the mouse pointer at the time a file was dropped during a drag-and-drop operation.

## Parameters

### `hDrop` [in]

Type: **HDROP**

Handle of the drop structure that describes the dropped file.

### `ppt` [out]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)***

Pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that, when this function returns successfully, receives the coordinates of the mouse pointer at the time the file was dropped.

## Return value

Type: **BOOL**

**TRUE** if the drop occurred in the client area of the window; otherwise **FALSE**.

## Remarks

The window for which coordinates are returned is the window that received the [WM_DROPFILES](https://learn.microsoft.com/windows/desktop/shell/wm-dropfiles) message.

## See also

[DragQueryFile](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-dragqueryfilea)