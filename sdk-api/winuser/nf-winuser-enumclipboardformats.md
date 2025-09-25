# EnumClipboardFormats function

## Description

Enumerates the data formats currently available on the clipboard.

Clipboard data formats are stored in an ordered list. To perform an enumeration of clipboard data formats, you make a series of calls to the **EnumClipboardFormats** function. For each call, the *format* parameter specifies an available clipboard format, and the function returns the next available clipboard format.

## Parameters

### `format` [in]

Type: **UINT**

A clipboard format that is known to be available.

To start an enumeration of clipboard formats, set
*format* to zero. When
*format* is zero, the function retrieves the first available clipboard format. For subsequent calls during an enumeration, set
*format* to the result of the previous
**EnumClipboardFormats** call.

## Return value

Type: **UINT**

If the function succeeds, the return value is the clipboard format that follows the specified format, namely the next available clipboard format.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the clipboard is not open, the function fails.

If there are no more clipboard formats to enumerate, the return value is zero. In this case, the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns the value **ERROR_SUCCESS**. This lets you distinguish between function failure and the end of enumeration.

## Remarks

You must open the clipboard before enumerating its formats. Use the [OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard) function to open the clipboard. The **EnumClipboardFormats** function fails if the clipboard is not open.

The
**EnumClipboardFormats** function enumerates formats in the order that they were placed on the clipboard. If you are copying information to the clipboard, add clipboard objects in order from the most descriptive clipboard format to the least descriptive clipboard format. If you are pasting information from the clipboard, retrieve the first clipboard format that you can handle. That will be the most descriptive clipboard format that you can handle.

The system provides automatic type conversions for certain clipboard formats. In the case of such a format, this function enumerates the specified format, then enumerates the formats to which it can be converted. For more information, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats) and [Synthesized Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

#### Examples

For an example, see [Example of a Clipboard Viewer](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[CountClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-countclipboardformats)

[OpenClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-openclipboard)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)