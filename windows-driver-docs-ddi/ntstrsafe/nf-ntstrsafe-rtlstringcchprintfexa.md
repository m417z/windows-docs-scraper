# RtlStringCchPrintfExA function

## Description

The **RtlStringCchPrintfExW** and **RtlStringCchPrintfExA** functions create a character-counted text string, with formatting that is based on supplied formatting information.

## Parameters

### `pszDest` [out, optional]

A pointer to a caller-supplied buffer that receives a formatted, null-terminated string. The function creates this string from both the formatting string that is supplied by *pszFormat* and the function's argument list. The *pszDest* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cchDest` [in]

The size of the destination buffer, in characters. The buffer must be large enough to contain the formatted string plus the terminating null character. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH. If *pszDest* is **NULL**, *cchDest* must be zero.

### `ppszDestEnd` [out, optional]

If the caller supplies a non-**NULL** address pointer then, after the operation completes, the function loads that address with a pointer to the destination buffer's resulting **NULL** string terminator.

### `pcchRemaining` [out, optional]

If the caller supplies a non-**NULL** address pointer, the function loads the address with the number of unused characters in the buffer pointed to by *pszDest*, including the terminating null character.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL** | If set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the terminating null character. |
| **STRSAFE_IGNORE_NULLS** | If set, either *pszDest* or *pszSrc*, or both, can be **NULL**. **NULL** *pszSrc* pointers are treated like empty strings (TEXT("")), which can be copied. **NULL** *pszDest* pointers cannot receive nonempty strings. |
| **STRSAFE_FILL_ON_FAILURE** | If set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer, and the buffer is null-terminated. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If set and the function returns STATUS_BUFFER_OVERFLOW, the contents of the destination buffer are not modified. |

### `pszFormat` [in]

A pointer to a null-terminated text string that contains **printf**-styled formatting directives. The *pszFormat* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `...`

An optional list of arguments that are interpreted by the function, based on formatting directives contained in the *pszFormat* string.

## Return value

The function returns one of the **NTSTATUS** values that are listed in the following table. For information about how to test **NTSTATUS** values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the output string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. If STRSAFE_NO_TRUNCATION is set in *dwFlags*, the destination buffer is not modified. If the flag is not set, the destination buffer contains a truncated version of the created string. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* An invalid flag was specified.<br>* The value in *cchDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present without the STRSAFE_IGNORE_NULLS flag.<br>* The destination buffer pointer was **NULL**, but the buffer size was not zero.<br>* The destination buffer pointer was **NULL**, or its length was zero, but a nonzero length source string was present. |

## Remarks

**RtlStringCchPrintfExW** and **RtlStringCchPrintfExA** should be used instead of the following functions:

* **sprintf**
* **swprintf**
* _**snprintf**
* _**snwprintf**

All of these functions accept a format string and a list of arguments and return a formatted string. **RtlStringCchPrintfExW** and **RtlStringCchPrintfExA** accept the size, in characters, of the destination buffer to ensure that they do not write past the end of this buffer.

**RtlStringCchPrintfExW** and **RtlStringCchPrintfExA** add to the functionality of [RtlStringCchPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfa) by returning a pointer to the end of the destination string, as well as the number of characters left unused in that string. Flags can be passed to the function for additional control.

Use **RtlStringCchPrintfExW** to handle Unicode strings and **RtlStringCchPrintfExA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchPrintfExW** |
| **char** | "string" | **RtlStringCchPrintfExA** |

If *pszDest* and *pszFormat* point to overlapping strings, or any argument strings overlap, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set, in which case either or both can be **NULL**. If *pszDest* is **NULL**, *pszSrc* must either be **NULL** or point to an empty string.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbprintfexa)

[RtlStringCchPrintf](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchprintfa)

[RtlStringCchVPrintfEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchvprintfexa)