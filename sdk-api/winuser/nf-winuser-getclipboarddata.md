# GetClipboardData function

## Description

Retrieves data from the clipboard in a specified format. The clipboard must have been opened previously.

## Parameters

### `uFormat` [in]

Type: **UINT**

A clipboard format. For a description of the standard clipboard formats, see [Standard Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

## Return value

Type: **HANDLE**

If the function succeeds, the return value is the handle to a clipboard object in the specified format.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Caution** Clipboard data is not trusted. Parse the data carefully before using it in your application.

An application can enumerate the available formats in advance by using the [EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats) function.

The clipboard controls the handle that the **GetClipboardData** function returns, not the application. The application should copy the data immediately. The application must not free the handle nor leave it locked. The application must not use the handle after the [EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard) or [CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard) function is called, or after the [SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata) function is called with the same clipboard format.

The system performs implicit data format conversions between certain clipboard formats when an application calls the **GetClipboardData** function. For example, if the [CF_OEMTEXT](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats) format is on the clipboard, a window can retrieve data in the [CF_TEXT](https://learn.microsoft.com/windows/desktop/dataxchg/standard-clipboard-formats) format. The format on the clipboard is converted to the requested format on demand. For more information, see [Synthesized Clipboard Formats](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard-formats).

#### Examples

For an example, see [Copying Information to the Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

[CloseClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-closeclipboard)

**Conceptual**

[EmptyClipboard](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-emptyclipboard)

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

**Reference**

[SetClipboardData](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setclipboarddata)