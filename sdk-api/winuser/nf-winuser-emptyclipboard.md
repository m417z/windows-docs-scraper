# EmptyClipboard function

## Description

Empties the clipboard and frees handles to data in the clipboard. The function then assigns ownership of the clipboard to the window that currently has the clipboard open.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Before calling **EmptyClipboard**, an application must open the clipboard by using the [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function. If the application specifies a **NULL** window handle when opening the clipboard, **EmptyClipboard** succeeds but sets the clipboard owner to **NULL**. Note that this causes [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) to fail.

#### Examples

For an example, see [Copying Information to the Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard)

**Reference**

[SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata)

[WM_DESTROYCLIPBOARD](https://learn.microsoft.com/windows/desktop/dataxchg/wm-destroyclipboard)