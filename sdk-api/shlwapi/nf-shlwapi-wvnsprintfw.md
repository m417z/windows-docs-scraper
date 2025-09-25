# wvnsprintfW function

## Description

Takes a list of arguments and returns the values of the arguments as a [printf](https://learn.microsoft.com/windows/desktop/direct3dhlsl/printf)-style formatted string.

**Note** Do not use this function. See Remarks for alternative functions.

## Parameters

### `pszDest` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the output string.

### `cchDest` [in]

Type: **int**

The maximum number of characters allowed in *pszDest*.

### `pszFmt` [in]

Type: **PCTSTR**

A [printf](https://learn.microsoft.com/windows/win32/api/shlwapi/cpp/c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l)-style format string. The %s format identifier should never be used in an unbounded form. To avoid potential buffer overruns, always specify a size; for instance "%32s".

### `arglist` [in]

Type: **va_list**

A pointer to a list of command-line parameters used to customize the output.

## Return value

Type: **int**

Returns the number of characters written to the buffer, excluding any terminating **NULL** characters. A negative value is returned if an error occurs.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The copied string is not guaranteed to be null-terminated. Consider using one of the following alternatives. [StringCbPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfa), [StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa), [StringCbVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfa), [StringCbVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbvprintfexa), [StringCchPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfa), [StringCchPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchprintfexa), [StringCchVPrintf](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfa), or [StringCchVPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchvprintfexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.

> [!NOTE]
> The shlwapi.h header defines wvnsprintf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).