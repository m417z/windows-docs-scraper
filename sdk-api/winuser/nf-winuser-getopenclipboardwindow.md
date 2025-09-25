# GetOpenClipboardWindow function

## Description

Retrieves the handle to the window that currently has the clipboard open.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the window that has the clipboard open. If no window has the clipboard open, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If an application or DLL specifies a **NULL** window handle when calling the [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function, the clipboard is opened but is not associated with a window. In such a case, **GetOpenClipboardWindow** returns **NULL**.

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[GetClipboardOwner](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardowner)

[GetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardviewer)

[OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard)

**Reference**