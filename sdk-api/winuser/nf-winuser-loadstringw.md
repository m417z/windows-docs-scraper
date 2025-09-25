# LoadStringW function

## Description

Loads a string resource from the executable file associated with a specified module and either copies the string into a buffer with a terminating null character or returns a read-only pointer to the string resource itself.

## Parameters

### `hInstance` [in, optional]

Type: **HINSTANCE**

A handle to an instance of the module whose executable file contains the string resource. To get the handle to the application itself, call the [GetModuleHandle](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getmodulehandlea) function with **NULL**.

### `uID` [in]

Type: **UINT**

The identifier of the string to be loaded.

### `lpBuffer` [out]

Type: **LPTSTR**

The buffer to receive the string (if *cchBufferMax* is non-zero) or a read-only pointer to the string resource itself (if *cchBufferMax* is zero). Must be of sufficient length to hold a pointer (8 bytes).

### `cchBufferMax` [in]

Type: **int**

The size of the buffer, in characters. The string is truncated and null-terminated if it is longer than the number of characters specified. If this parameter is 0, then *lpBuffer* receives a read-only pointer to the string resource itself.

## Return value

Type: **int**

If the function succeeds, the return value is one of the following:

- The number of characters copied into the buffer (if *cchBufferMax* is non-zero), not including the terminating null character.
- The number of characters in the string resource that *lpBuffer* points to (if *cchBufferMax* is zero). The string resource is not guaranteed to be null-terminated in the module's resource table, and you can use this value to determine where the string resource ends.
- Zero if the string resource does not exist.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If you pass 0 to *cchBufferMax* to return a read-only pointer to the string resource in the *lpBuffer* parameter, use the number of characters in the return value to determine the length of the string resource. String resources are not guaranteed to be null-terminated in the module's resource table. However, resource tables can contain null characters. String resources are stored in blocks of 16 strings, and any empty slots within a block are indicated by null characters.

### Security Remarks

Using this function incorrectly can compromise the security of your application. Incorrect use includes specifying the wrong size in the *nBufferMax* parameter. For example, if *lpBuffer* points to a buffer *szBuffer* which is declared as `TCHAR szBuffer[100]`, then sizeof(szBuffer) gives the size of the buffer in bytes, which could lead to a buffer overflow for the Unicode version of the function. Buffer overflow situations are the cause of many security problems in applications. In this case, using `sizeof(szBuffer)/sizeof(TCHAR)` or `sizeof(szBuffer)/sizeof(szBuffer[0])` would give the proper size of the buffer.

#### Examples

For an example, see [Creating a Child Window](https://learn.microsoft.com/windows/desktop/winmsg/using-the-multiple-document-interface)

> [!NOTE]
> The winuser.h header defines LoadString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[LoadAccelerators](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadacceleratorsa)

[LoadBitmap](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadbitmapa)

[LoadCursor](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadcursora)

[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)

[LoadMenu](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenua)

[LoadMenuIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadmenuindirecta)

**Other Resources**

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)