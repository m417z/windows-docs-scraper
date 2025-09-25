# StrCatBuffA function

## Description

Copies and appends characters from one string to the end of another.

**Note** Do not use. See Remarks for alternative functions.

## Parameters

### `pszDest` [in, out]

Type: **PTSTR**

A pointer to a null-terminated string. When this function returns successfully, this string contains its original content with the string *pszSrc* appended.

### `pszSrc` [in]

Type: **PCTSTR**

A pointer to the string to be appended to *pszDest*.

### `cchDestBuffSize`

Type: **int**

The size of the buffer, in characters, pointed to by *pszDest*. This value must be at least the length of the combined string plus the terminating null character. If the buffer is too small to fit the entire string, the string will be truncated.

## Return value

Type: **PTSTR**

Returns a pointer to the destination string.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The final string is not guaranteed to be null-terminated. Consider using one of the following alternatives: [StringCbCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcata), [StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa), [StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna), [StringCbCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatnexa), [StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata), [StringCchCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatexa), [StringCchCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatna), or [StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.

> [!NOTE]
> The shlwapi.h header defines StrCatBuff as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).