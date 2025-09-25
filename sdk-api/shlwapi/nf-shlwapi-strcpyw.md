# StrCpyW function

## Description

Copies one string to another.

**Note** Do not use. See Remarks for alternative functions.

## Parameters

### `psz1` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the copied string. This string is not guaranteed to be null-terminated.

### `psz2` [in]

Type: **PCTSTR**

A pointer to the null-terminated source string.

## Return value

Type: **PTSTR**

Returns a pointer to *psz1*.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The first argument, *psz1*, must be large enough to hold *psz2* and the closing '\0', otherwise a buffer overrun may occur. Buffer overruns may lead to a denial of service attack against the application if an access violation occurs. In the worst case, a buffer overrun may allow an attacker to inject executable code into your process, especially if *psz1* is a stack-based buffer. Consider using one of the following alternatives: [StringCbCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopya), [StringCbCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyexa), [StringCbCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopyna), [StringCbCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcopynexa), [StringCchCopy](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopya), [StringCchCopyEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyexa), [StringCchCopyN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopyna), or [StringCchCopyNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcopynexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.