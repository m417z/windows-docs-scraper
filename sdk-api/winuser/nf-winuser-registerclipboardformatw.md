# RegisterClipboardFormatW function

## Description

Registers a new clipboard format. This format can then be used as a valid clipboard format.

## Parameters

### `lpszFormat` [in]

Type: **LPCTSTR**

The name of the new format.

## Return value

Type: **UINT**

If the function succeeds, the return value identifies the registered clipboard format.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a registered format with the specified name already exists, a new format is not registered and the return value identifies the existing format. This enables more than one application to copy and paste data using the same registered clipboard format. Note that the format name comparison is case-insensitive.

Registered clipboard formats are identified by values in the range 0xC000 through 0xFFFF.

When registered clipboard formats are placed on or retrieved from the clipboard, they must be in the form of an
**HGLOBAL** value.

#### Examples

For an example, see [Registering a Clipboard Format](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

> [!NOTE]
> The winuser.h header defines RegisterClipboardFormat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[CountClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-countclipboardformats)

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

[GetClipboardFormatName](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclipboardformatnamea)

**Reference**