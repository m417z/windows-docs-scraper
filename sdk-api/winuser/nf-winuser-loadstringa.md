# LoadStringA function

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

The buffer to receive the string. Must be at least *cchBufferMax* characters in size.

### `cchBufferMax` [in]

Type: **int**

The size of the buffer, in characters. The string is truncated and null-terminated if it is longer than the number of characters specified.
This parameter may not be zero.

## Return value

Type: **int**

If the function succeeds, the return value is the number of characters copied into the buffer, not including the terminating null character.

If the string resource does not exist, the return value is zero.
To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Unlike the **LoadStringW** function, the **LoadStringA** function does not support passing a value of zero for *cchBufferMax*.
Doing so will corrupt memory.

### Security Remarks

Using this function incorrectly can compromise the security of your application. Incorrect use includes specifying the wrong size in the *cchBufferMax* parameter. For example, if *lpBuffer* points to a buffer *szBuffer* which is declared as `TCHAR szBuffer[100]`, then sizeof(szBuffer) gives the size of the buffer in bytes, which could lead to a buffer overflow for the Unicode version of the function. Buffer overflow situations are the cause of many security problems in applications. In this case, using `sizeof(szBuffer)/sizeof(TCHAR)` or `sizeof(szBuffer)/sizeof(szBuffer[0])` would give the proper size of the buffer.

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