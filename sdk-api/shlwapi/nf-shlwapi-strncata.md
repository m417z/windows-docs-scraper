# StrNCatA function

## Description

Appends a specified number of characters from the beginning of one string to the end of another.

**Note** Do not use this function or the **StrCatN** macro. See Remarks for alternative functions.

## Parameters

### `psz1` [in, out]

Type: **PTSTR**

A pointer to a null-terminated string to which the function appends the characters from *psz2*. It must be large enough to hold the combined strings plus the terminating null character.

### `psz2`

Type: **PCTSTR**

A pointer to the null-terminated string to be appended.

### `cchMax`

Type: **int**

The number of characters to be appended to *psz1* from the beginning of *psz2*.

## Return value

Type: **PTSTR**

Returns a pointer to *psz1*, which holds the combined string.

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. The first argument, *psz1*, must be large enough to hold *psz2* and the closing '\0', otherwise a buffer overrun may occur. Buffer overruns may lead to a denial of service attack against the application if an access violation occurs. In the worst case, a buffer overrun may allow an attacker to inject executable code into your process, especially if *psz1* is a stack-based buffer. Be aware that the last argument, *cchMax*, is the number of characters to copy into *psz1*, not necessarily the size of the *psz1* in bytes. Consider using one of the following alternatives. [StringCbCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcata), [StringCbCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatexa), [StringCbCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatna), [StringCbCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbcatnexa), [StringCchCat](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcata), [StringCchCatEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatexa), [StringCchCatN](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatna), or [StringCchCatNEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcchcatnexa). You should review [Security Considerations: Microsoft Windows Shell](https://learn.microsoft.com/windows/desktop/shell/sec-shell) before continuing.

> [!NOTE]
> The shlwapi.h header defines StrNCat as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).