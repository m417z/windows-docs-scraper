# GetClipboardViewer function

## Description

Retrieves the handle to the first window in the clipboard viewer chain.

## Return value

Type: **HWND**

If the function succeeds, the return value is the handle to the first window in the clipboard viewer chain.

If there is no clipboard viewer, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[GetClipboardOwner](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardowner)

**Reference**

[SetClipboardViewer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboardviewer)