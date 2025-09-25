# OemToCharBuffW function

## Description

Translates a specified number of characters in a string from the OEM-defined character set into either an ANSI or a wide-character string.

## Parameters

### `lpszSrc` [in]

Type: **LPCSTR**

One or more characters from the OEM-defined character set.

### `lpszDst` [out]

Type: **LPTSTR**

The destination buffer, which receives the translated string. If the **OemToCharBuff** function is being used as an ANSI function, the string can be translated in place by setting the
*lpszDst* parameter to the same address as the
*lpszSrc* parameter. This cannot be done if the **OemToCharBuff** function is being used as a wide-character function.

### `cchDstLength` [in]

Type: **DWORD**

The number of
characters to be translated in the buffer identified by the
*lpszSrc* parameter.

## Return value

Type: **BOOL**

The return value is always nonzero except when you pass the same address to
*lpszSrc* and
*lpszDst* in the wide-character version of the function. In this case the function returns zero and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_ADDRESS**.

## Remarks

Unlike the [OemToChar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-oemtochara) function, the **OemToCharBuff** function does not stop converting characters when it encounters a null character in the buffer pointed to by
*lpszSrc*. The **OemToCharBuff** function converts all
*cchDstLength* characters.

> [!NOTE]
> The winuser.h header defines OemToCharBuff as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CharToOem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-chartooema)

[CharToOemBuff](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-chartooembuffa)

**Conceptual**

[OemToChar](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-oemtochara)

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)