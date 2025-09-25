# CountClipboardFormats function

## Description

Retrieves the number of different data formats currently on the clipboard.

## Return value

Type: **int**

If the function succeeds, the return value is the number of different data formats currently on the clipboard.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)