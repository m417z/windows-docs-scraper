# RtlStringCchCatExA function

## Description

The **RtlStringCchCatExW** and **RtlStringCchCatExA** functions concatenate two character-counted strings.

## Parameters

### `pszDest` [in, out, optional]

A pointer to a buffer which, on input, contains a null-terminated string to which *pszSrc* will be concatenated. On output, this is the destination buffer that contains the entire resultant string. The string at *pszSrc* is added to the end of the string at *pszDest* and terminated with a null character. The *pszDest* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cchDest` [in]

The size of the destination buffer, in characters. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH. If *pszDest* is **NULL**, *cchDest* must be zero.

### `pszSrc` [in]

A pointer to a null-terminated string. This string will be concatenated to the end of the string that is contained in the buffer at *pszDest*. The *pszSrc* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `ppszDestEnd` [out, optional]

If the caller supplies a non-**NULL** address pointer, then after the concatenation operation completes, the function loads that address with a pointer to the destination buffer's resulting null string terminator.

### `pcchRemaining` [out, optional]

If the caller supplies a non-**NULL** address pointer, the function loads the address with the number of unused characters that are in the buffer pointed to by *pszDest*, including the terminating null character.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL** | If set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the terminating null character. |
| **STRSAFE_IGNORE_NULLS** | If set, either *pszDest* or *pszSrc*, or both, can be **NULL**. **NULL** *pszSrc* pointers are treated like empty strings (TEXT("")), which can be copied. **NULL** *pszDest* pointers cannot receive nonempty strings. |
| **STRSAFE_FILL_ON_FAILURE** | If set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer, and the buffer is null-terminated. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If set and the function returns STATUS_BUFFER_OVERFLOW:<br><br>* If **STRSAFE_FILL_ON_FAILURE** is also specified, **STRSAFE_NO_TRUNCATION** fills the destination buffer   accordingly.<br>* Otherwise, the destination buffer will be unmodified. |

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the output string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. If **STRSAFE_NO_TRUNCATION** is set, see the *dwFlags* parameter for more information. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* An invalid flag was specified.<br>* The value in *cchDest*  is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present without the **STRSAFE_IGNORE_NULLS** flag.<br>* The destination buffer pointer was **NULL**, but the buffer size was not zero.<br>* The destination buffer pointer was **NULL**, or its length was zero, but a nonzero length source string   was present. |

## Remarks

**RtlStringCchCatExW** and **RtlStringCchCatExA** should be used instead of the following functions:

- **strcat**
- **wcscat**

The size, in characters, of the destination buffer is provided to ensure that **RtlStringCchCatExW** and **RtlStringCchCatExA** do not write past the end of the buffer.

**RtlStringCchCatExW** and **RtlStringCchCatExA** add to the functionality of [RtlStringCchCat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcata) by returning a pointer to the end of the destination string, as well as the number of characters left unused in the destination buffer. Flags can be passed to the function for additional control.

Use **RtlStringCchCatExW** to handle Unicode strings and **RtlStringCchCatExA** to handle ANSI strings. The form you use depends on your data.

| String data type | String literal | Function |
|--|--|--|
| **WCHAR** | L"string" | **RtlStringCchCatExW** |
| **char** | "string" | **RtlStringCchCatExA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set, in which case either or both can be **NULL**. If *pszDest* is **NULL**, *pszSrc* must either be **NULL** or point to an empty string.

For more information about the safe string functions, see [Using safe string functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

- [RtlStringCbCatEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcatexa)
- [RtlStringCchCat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcata)
- [RtlStringCchCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatnexa)