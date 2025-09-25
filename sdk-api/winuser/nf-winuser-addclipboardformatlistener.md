# AddClipboardFormatListener function

## Description

Places the given window in the system-maintained clipboard format listener list.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window to be placed in the clipboard format listener list.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, **FALSE** otherwise. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional details.

## Remarks

When a window has been added to the clipboard format listener list, it is posted a [WM_CLIPBOARDUPDATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-clipboardupdate) message whenever the contents of the clipboard have changed.

## See also

[GetClipboardSequenceNumber](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardsequencenumber)

[RemoveClipboardFormatListener](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-removeclipboardformatlistener)

[WM_CLIPBOARDUPDATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-clipboardupdate)