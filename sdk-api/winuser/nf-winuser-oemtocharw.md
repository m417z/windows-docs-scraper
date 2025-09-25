# OemToCharW function

## Description

Translates a string from the OEM-defined character set into either an ANSI or a wide-character string.

**Warning** Do not use. See Security Considerations.

## Parameters

### `pSrc` [in]

Type: **LPCSTR**

A null-terminated string of characters from the OEM-defined character set.

### `pDst` [out]

Type: **LPTSTR**

The destination buffer, which receives the translated string. If the **OemToChar** function is being used as an ANSI function, the string can be translated in place by setting the *lpszDst* parameter to the same address as the *lpszSrc* parameter. This cannot be done if **OemToChar** is being used as a wide-character function.

## Return value

Type: **BOOL**

The return value is always nonzero except when you pass the same address to *lpszSrc* and *lpszDst* in the wide-character version of the function. In this case the function returns zero and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_ADDRESS**.

## See also

[CharToOem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-chartooema)

[CharToOemBuff](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-chartooembuffa)

**Conceptual**

[OemToCharBuff](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-oemtocharbuffa)

**Reference**

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

## Remarks

### Security Considerations

Using this function incorrectly might compromise the security of your program. For example, miscalculating the proper size of the *lpszDst* buffer, especially when the application is used in both ANSI and Unicode versions, can cause a buffer overflow. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/desktop/Intl/security-considerations--international-features) and [Security Considerations: Windows User Interface](https://learn.microsoft.com/windows/win32/appuistart/sec-ui).

> [!NOTE]
> The winuser.h header defines OemToChar as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).