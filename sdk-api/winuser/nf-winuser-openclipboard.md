# OpenClipboard function

## Description

Opens the clipboard for examination and prevents other applications from modifying the clipboard content.

## Parameters

### `hWndNewOwner` [in, optional]

Type: **HWND**

A handle to the window to be associated with the open clipboard. If this parameter is **NULL**, the open clipboard is associated with the current task.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**OpenClipboard** fails if another window has the clipboard open.

An application should call the [CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard) function after every successful call to **OpenClipboard**.

The window identified by the
*hWndNewOwner* parameter does not become the clipboard owner unless the [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) function is called.

If an application calls **OpenClipboard** with hwnd set to **NULL**, [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) sets the clipboard owner to **NULL**; this causes [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) to fail.

#### Examples

For an example, see [Copying Information to the Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

[CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard)

**Conceptual**

[EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard)

**Reference**