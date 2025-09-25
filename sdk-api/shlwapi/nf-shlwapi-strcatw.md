# StrCatW function

## Description

Appends one string to another.

**Note** Do not use. See Remarks for alternative functions.

## Parameters

### `psz1` [in, out]

Type: **PTSTR**

A pointer to a null-terminated string. When this function returns successfully, this string contains its original content with the string *psz2* appended. This buffer must be large enough to hold both strings and the terminating null character.

### `psz2` [in]

Type: **PCTSTR**

A pointer to a null-terminated string to be appended to *psz1*.

## Return value

Type: **PTSTR**

Returns a pointer to *psz1*, which holds the combined strings.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The first argument, *psz1*, must be large enough to hold *psz2* and the closing '\0', otherwise a buffer overrun may occur. Buffer overruns may lead to a denial of service attack against the application if an access violation occurs. In the worst case, a buffer overrun may allow an attacker to inject executable code into your process, especially if *psz1* is a stack-based buffer. Consider using one of the following alternatives: [StringCbCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcata), [StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa), [StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna), [StringCbCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatnexa), [StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata), [StringCchCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatexa), [StringCchCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatna), or [StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.