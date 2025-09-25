# CloseClipboard function

## Description

Closes the clipboard.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When the window has finished examining or changing the clipboard, close the clipboard by calling **CloseClipboard**. This enables other windows to access the clipboard.

Do not place an object on the clipboard after calling **CloseClipboard**.

#### Examples

For an example, see [Example of a Clipboard Viewer](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[GetOpenClipboardWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getopenclipboardwindow)

[OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard)

**Reference**