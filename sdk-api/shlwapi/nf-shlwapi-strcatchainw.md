# StrCatChainW function

## Description

Concatenates two Unicode strings. Used when repeated concatenations to the same buffer are required.

## Parameters

### `pszDst` [out]

Type: **PWSTR**

A pointer to a buffer that, when this function returns successfully, receives the null-terminated, Unicode string.

### `cchDst`

Type: **DWORD**

The size of the destination buffer, in characters. This buffer must be of sufficient size to hold both strings as well as a terminating null character. If the buffer is too small, the final string is truncated.

### `ichAt`

Type: **DWORD**

The offset into the destination buffer at which to begin the append action. If the string is not empty, set this value to -1 to have the current number of filled characters (not including the terminating null character) calculated for you.

### `pszSrc` [in]

Type: **PCWSTR**

A pointer to the null-terminated Unicode source string.

## Return value

Type: **DWORD**

Returns the offset of the null character after the last character added to *pszDst*.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The final string is not guaranteed to be null-terminated. Consider using one of the following alternatives: [StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa), [StringCbCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatnexa), [StringCchCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatexa), or [StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.