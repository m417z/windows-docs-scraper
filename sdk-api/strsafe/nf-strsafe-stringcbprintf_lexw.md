# StringCbPrintf_lExW function

## Description

Writes formatted data to the specified string. The size of the destination buffer is provided to the function to ensure that it does not write past the end of this buffer.

**StringCbPrintf_lEx** is similar to [StringCbPrintfEx](https://learn.microsoft.com/windows/desktop/api/strsafe/nf-strsafe-stringcbprintfexa) but includes a parameter for locale information.

## Parameters

### `pszDest` [out]

The destination buffer, which receives the formatted, null-terminated string created from *pszFormat* and its arguments.

### `cbDest` [in]

The size of the destination buffer, in bytes. This value must be sufficiently large to accommodate the final formatted string plus the terminating null character. The maximum number of bytes allowed is `STRSAFE_MAX_CCH * sizeof(TCHAR)`.

### `ppszDestEnd` [out]

The address of a pointer to the end of *pszDest*. If *ppszDestEnd* is non-**NULL** and any data is copied into the destination buffer, this points to the terminating null character at the end of the string.

### `pcbRemaining` [out, optional]

The number of unused bytes in *pszDest*, including those used for the terminating null character. If *pcbRemaining* is **NULL**, the count is not kept or returned.

### `dwFlags` [in]

One or more of the following values.

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL**<br><br>0x00000200 | If the function succeeds, the low byte of *dwFlags* (0) is used to fill the uninitialized portion of *pszDest* following the terminating null character. |
| **STRSAFE_IGNORE_NULLS**<br><br>0x00000100 | Treat **NULL** string pointers like empty strings (TEXT("")). |
| **STRSAFE_FILL_ON_FAILURE**<br><br>0x00000400 | If the function fails, the low byte of *dwFlags* (0) is used to fill the entire *pszDest* buffer, and the buffer is null-terminated. In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string returned is overwritten. |
| **STRSAFE_NULL_ON_FAILURE**<br><br>0x00000800 | If the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |
| **STRSAFE_NO_TRUNCATION**<br><br>0x00001000 | As in the case of **STRSAFE_NULL_ON_FAILURE**, if the function fails, *pszDest* is set to an empty string (TEXT("")). In the case of a **STRSAFE_E_INSUFFICIENT_BUFFER** failure, any truncated string is overwritten. |

### `pszFormat` [in]

The format string. This string must be null-terminated. For more information, see [Format Specification Syntax](https://learn.microsoft.com/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions).

### `locale` [in]

The locale object. For more information, see **_create_locale**.

### `...`

The arguments to be inserted into the *pszFormat* string.

## Return value

This function can return one of the following values. It is strongly recommended that you use the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros to test the return value of this function.

| Return code | Description |
| --- | --- |
| **S_OK** | There was sufficient space for the result to be copied to *pszDest* without truncation, and the buffer is null-terminated. |
| **STRSAFE_E_INVALID_PARAMETER** | The value in *cbDest* is either 0 or larger than `STRSAFE_MAX_CCH * sizeof(TCHAR)`, or the destination buffer is already full. |
| **STRSAFE_E_INSUFFICIENT_BUFFER** | The copy operation failed due to insufficient buffer space. Depending on the value of *dwFlags*, the destination buffer may contain a truncated, null-terminated version of the intended result. In situations where truncation is acceptable, this may not necessarily be seen as a failure condition. |

## Remarks

Behavior is undefined if the strings pointed to by *pszDest*, *pszFormat*, or any argument strings overlap.

Neither *pszFormat* nor *pszDest* should be **NULL** unless the **STRSAFE_IGNORE_NULLS** flag is specified, in which case both may be **NULL**. However, an error due to insufficient space may still be returned even though **NULL** values are ignored.

In order to use this function, you must define the following macro in your header file, before including StrSafe.h.

`#define STRSAFE_LOCALE_FUNCTIONS`

> [!NOTE]
> The strsafe.h header defines StringCbPrintf_lEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).