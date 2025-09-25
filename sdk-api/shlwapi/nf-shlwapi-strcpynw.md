# StrCpyNW function

## Description

Copies a specified number of characters from the beginning of one string to another.

**Note** Do not use this function or the **StrNCpy** macro. See Remarks for alternative functions.

## Parameters

### `pszDst` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the copied string. This buffer must be of sufficient size to hold the copied characters. This string is not guaranteed to be null-terminated.

### `pszSrc` [in]

Type: **PCTSTR**

A pointer to the null-terminated source string.

### `cchMax`

Type: **int**

The number of characters to be copied, including the terminating null character.

## Return value

Type: **PTSTR**

Returns a pointer to *pszDst*.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The copied string is not guaranteed to be null-terminated. Consider using one of the following alternatives. [StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya), [StringCbCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyexa), [StringCbCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyna), [StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa), [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya), [StringCchCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyexa), [StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna), [StringCchCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopynexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.