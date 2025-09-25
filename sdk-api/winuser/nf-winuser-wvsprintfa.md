# wvsprintfA function

## Description

Writes formatted data to the specified buffer using a pointer to a list of arguments. The items pointed to by the argument list are converted and copied to an output buffer according to the corresponding format specification in the format-control string. The function appends a terminating null character to the characters it writes, but the return value does not include the terminating null character in its character count.

**Warning** Do not use. Consider using one of the following functions instead: [StringCbVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfa),
[StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa), [StringCchVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfa), or
[StringCchVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfexa). See Security Considerations.

## Parameters

### `unnamedParam1` [out]

Type: **LPTSTR**

The buffer that is to receive the formatted output. The maximum size of the buffer is 1,024 bytes.

### `unnamedParam2` [in]

Type: **LPCTSTR**

The format-control specifications. In addition to ordinary ASCII characters, a format specification for each argument appears in this string. For more information about the format specification, see the [wsprintf](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-wsprintfa) function.

### `arglist` [in]

Type: **va_list**

Each element of this list specifies an argument for the format-control string. The number, type, and interpretation of the arguments depend on the corresponding format-control specifications in the
*lpFmt* parameter.

## Return value

Type: **int**

If the function succeeds, the return value is the number of characters stored in the buffer, not counting the terminating null character.

If the function fails, the return value is less than the length of the expected output. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function copies the format-control string into the output buffer character by character, starting with the first character in the string. When it encounters a format specification in the string, the function retrieves the value of the next available argument (starting with the first argument in the list), converts that value into the specified format, and copies the result to the output buffer. The function continues to copy characters and expand format specifications in this way until it reaches the end of the format-control string. If there are more arguments than format specifications, the extra arguments are ignored. If there are not enough arguments for all of the format specifications, the results are undefined.

> [!NOTE]
> The winuser.h header defines wvsprintf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

**Reference**

[StringCbPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfa)

[StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa)

[StringCbVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfa)

[StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa)

[StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa)

[StringCchPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfexa)

[StringCchVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfa)

[StringCchVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfexa)

[Strings](https://learn.microsoft.com/windows/desktop/menurc/strings)

[wsprintf](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-wsprintfa)