# GetPriorityClipboardFormat function

## Description

Retrieves the first available clipboard format in the specified list.

## Parameters

### `paFormatPriorityList` [in]

Type: **UINT***

The clipboard formats, in priority order. For a description of the standard clipboard formats, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats) .

### `cFormats` [in]

Type: **int**

The number of entries in the
*paFormatPriorityList* array. This value must not be greater than the number of entries in the list.

## Return value

Type: **int**

If the function succeeds, the return value is the first clipboard format in the list for which data is available. If the clipboard is empty, the return value is NULL. If the clipboard contains data, but not in any of the specified formats, the return value is –1. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[CountClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-countclipboardformats)

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

[GetClipboardFormatName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardformatnamea)

[IsClipboardFormatAvailable](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-isclipboardformatavailable)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)