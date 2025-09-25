# RemoveClipboardFormatListener function

## Description

Removes the given window from the system-maintained clipboard format listener list.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window to remove from the clipboard format listener list.

## Return value

Type: **BOOL**

Returns **TRUE** if successful, **FALSE** otherwise. Call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) for additional details.

## Remarks

When a window has been removed from the clipboard format listener list, it will no longer receive [WM_CLIPBOARDUPDATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-clipboardupdate) messages.

## See also

[AddClipboardFormatListener](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-addclipboardformatlistener)

[GetClipboardSequenceNumber](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardsequencenumber)

[WM_CLIPBOARDUPDATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-clipboardupdate)