# RtlStringCbCopyExW function

## Description

The **RtlStringCbCopyExW** and **RtlStringCbCopyExA** functions copy a byte-counted string into a buffer.

## Parameters

### `pszDest` [out, optional]

A pointer to a caller-supplied buffer that receives the copied string. The string at *pszSrc* is copied to the buffer at *pszDest* and terminated with a null character. The *pszDest* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cbDest` [in]

The size, in bytes, of the destination buffer. The buffer must be large enough for the string and the terminating null character.

For Unicode strings, the maximum number of bytes is `NTSTRSAFE_MAX_CCH * sizeof(WCHAR)`

For ANSI strings, the maximum number of bytes is `NTSTRSAFE_MAX_CCH * sizeof(char)`

If *pszDest* is **NULL**, *cbDest* must be zero.

### `pszSrc` [in, optional]

A pointer to a caller-supplied, null-terminated string. The *pszSrc* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `ppszDestEnd` [out, optional]

If the caller supplies a non-**NULL** address pointer, then after the copy operation completes, the function loads that address with a pointer to the destination buffer's resulting **NULL** string terminator.

### `pcbRemaining` [out, optional]

If the caller supplies a non-**NULL** address pointer, the function loads the address with the number of unused bytes that are in the buffer pointed to by *pszDest*, including bytes used for the terminating null character.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL** | If this flag is set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the terminating null character. |
| **STRSAFE_IGNORE_NULLS** | If this flag is set, either *pszDest* or *pszSrc*, or both, can be **NULL**. **NULL** *pszSrc* pointers are treated like empty strings (TEXT("")), which can be copied. **NULL** *pszDest* pointers cannot receive nonempty strings. |
| **STRSAFE_FILL_ON_FAILURE** | If this flag is set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer, and the buffer is null-terminated. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If this flag is set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If this flag is set and the function returns **STATUS_BUFFER_OVERFLOW**:<br><br>* If **STRSAFE_FILL_ON_FAILURE** is also specified, **STRSAFE_NO_TRUNCATION** fills the destination   buffer accordingly.<br>* Otherwise, the contents of the destination buffer will be set to an empty string, even if   **STRSAFE_NULL_ON_FAILURE** is not set. **STRSAFE_FILL_BEHIND_NULL** is ignored. |

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the copy operation did not complete due to insufficient space in the destination buffer. If **STRSAFE_NO_TRUNCATION** is set, see the *dwFlags* parameter for more information. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* An invalid flag was specified.<br>* The value in *cbDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present without the **STRSAFE_IGNORE_NULLS** flag.<br>* The destination buffer pointer was **NULL**, but the buffer size was not zero.<br>* The destination buffer pointer was **NULL**, or its length was zero, but a nonzero length source string   was present. |

## Remarks

**RtlStringCbCopyExA** and **RtlStringCbCopyExW** should be used instead of the following functions:

- **strcpy**
- **wcscpy**

The size, in bytes, of the destination buffer is provided to **RtlStringCbCopyExA** and **RtlStringCbCopyExW** to ensure that they do not write past the end of the buffer.

**RtlStringCbCopyEx** adds to the functionality of [RtlStringCbCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopya) by returning a pointer to the end of the destination string as well as the number of bytes left unused in that string. Flags can be passed to the function for additional control.

Use **RtlStringCbCopyExW** to handle Unicode strings and **RtlStringCbCopyExA** to handle ANSI strings. The form you use depends on your data as shown in the following table.

| String data type | String literal | Function |
|--|--|--|
| **WCHAR** | L"string" | **RtlStringCbCopyExW** |
| **char** | "string" | **RtlStringCbCopyExA** |

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set, in which case either or both can be **NULL**. If *pszDest* is **NULL**, *pszSrc* must either be **NULL** or point to an empty string.

For more information about the safe string functions, see [Using safe string functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

- [RtlStringCbCopy](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcopya)
- [RtlStringCchCopyEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcopyexa)