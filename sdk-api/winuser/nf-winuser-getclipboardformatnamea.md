# GetClipboardFormatNameA function

## Description

Retrieves from the clipboard the name of the specified registered format. The function copies the name to the specified buffer.

## Parameters

### `format` [in]

Type: **UINT**

The type of format to be retrieved. This parameter must not specify any of the predefined clipboard formats.

### `lpszFormatName` [out]

Type: **LPTSTR**

The buffer that is to receive the format name.

### `cchMaxCount` [in]

Type: **int**

The maximum length, in
characters, of the string to be copied to the buffer. If the name exceeds this limit, it is truncated.

## Return value

Type: **int**

If the function succeeds, the return value is the length, in
characters, of the string copied to the buffer.

If the function fails, the return value is zero, indicating that the requested format does not exist or is predefined. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

### Security Considerations

Using this function incorrectly might compromise the security of your program. For example, miscalculating the proper size of the *lpszFormatName* buffer, especially when the application is used in both ANSI and Unicode versions, can cause a buffer overflow. Also, note that the string is truncated if it is longer than the *cchMaxCount* parameter, which can lead to loss of information.

#### Examples

For an example, see [Example of a Clipboard Viewer](https://learn.microsoft.com/windows/desktop/dataxchg/using-the-clipboard).

> [!NOTE]
> The winuser.h header defines GetClipboardFormatName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)

**Conceptual**

[EnumClipboardFormats](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumclipboardformats)

**Reference**

[RegisterClipboardFormat](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-registerclipboardformata)