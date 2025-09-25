# GetClipboardOwner function

## Description

Retrieves the window handle of the current owner of the clipboard.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the window that owns the clipboard.

If the clipboard is not owned, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The clipboard can still contain data even if the clipboard is not currently owned.

In general, the clipboard owner is the window that last placed data in clipboard. The [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) function assigns clipboard ownership.

#### Examples

For an example, see [Example of a Clipboard Viewer](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard)

[GetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardviewer)

**Reference**