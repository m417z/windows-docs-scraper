# IsClipboardFormatAvailable function

## Description

Determines whether the clipboard contains data in the specified format.

## Parameters

### `format` [in]

Type: **UINT**

A standard or registered clipboard format. For a description of the standard clipboard formats, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats) .

## Return value

Type: **BOOL**

If the clipboard format is available, the return value is nonzero.

If the clipboard format is not available, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Typically, an application that recognizes only one clipboard format would call this function when processing the [WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu) or [WM_INITMENUPOPUP](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenupopup) message. The application would then enable or disable the Paste menu item, depending on the return value. Applications that recognize more than one clipboard format should use the [GetPriorityClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpriorityclipboardformat) function for this purpose.

#### Examples

For an example, see [Pasting Information from the Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[CountClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-countclipboardformats)

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

[GetPriorityClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getpriorityclipboardformat)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)

[WM_INITMENU](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenu)

[WM_INITMENUPOPUP](https://learn.microsoft.com/windows/desktop/menurc/wm-initmenupopup)