# RtlStringCchCatNExA function

## Description

**The RtlStringCchCatNExW** and **RtlStringCchCatNExA** functions concatenate two character-counted strings while limiting the size of the appended string.

## Parameters

### `pszDest` [in, out, optional]

A pointer to a buffer which, on input, contains a null-terminated string to which *pszSrc* will be concatenated. On output, this is the destination buffer that contains the entire resultant string. The string at *pszSrc*, up to *cchMaxAppend* characters, is added to the end of the string at *pszDest* and terminated with a null character. The *pszDest* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cchDest` [in]

The size of the destination buffer, in characters. The maximum number of characters allowed is NTSTRSAFE_MAX_CCH. If *pszDest* is **NULL**, *cchDest* must be zero.

### `pszSrc` [in, optional]

A pointer to a null-terminated string. This string will be concatenated to the end of the string that is contained in the buffer at *pszDest*. The *pszSrc* pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `cchToAppend`

The maximum number of characters to append to the string that is contained in the buffer at *pszDest*.

### `ppszDestEnd` [out, optional]

If the caller supplies a non-**NULL** address pointer, then after the concatenation operation completes, the function loads that address with a pointer to the destination buffer's resulting null string terminator.

### `pcchRemaining` [out, optional]

If the caller supplies a non-**NULL** address pointer, the function loads the address with the number of unused characters in the buffer pointed to by *pszDest*, including the terminating null character.

### `dwFlags` [in]

One or more flags and, optionally, a fill byte. The flags are defined as follows:

| Value | Meaning |
| --- | --- |
| **STRSAFE_FILL_BEHIND_NULL** | If this flag is set and the function succeeds, the low byte of *dwFlags* is used to fill the portion of the destination buffer that follows the terminating null character. |
| **STRSAFE_IGNORE_NULLS** | If this flag is set, either *pszDest* or *pszSrc*, or both, can be **NULL**. **NULL** *pszSrc* pointers are treated like empty strings (TEXT("")), which can be copied. **NULL** *pszDest* pointers cannot receive nonempty strings. |
| **STRSAFE_FILL_ON_FAILURE** | If this flag is set and the function fails, the low byte of *dwFlags* is used to fill the entire destination buffer, and the buffer is null-terminated. This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NULL_ON_FAILURE** | If this flag is set and the function fails, the destination buffer is set to an empty string (TEXT("")). This operation overwrites any preexisting buffer contents. |
| **STRSAFE_NO_TRUNCATION** | If this flag is set and the function returns **STATUS_BUFFER_OVERFLOW**:<br><br>* If **STRSAFE_FILL_ON_FAILURE** is also specified, **STRSAFE_NO_TRUNCATION** fills the destination buffer   accordingly.<br>* Otherwise, the destination buffer will be unmodified. |

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means source data was present, the output string was created without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_BUFFER_OVERFLOW** | This *warning* status means the operation did not complete due to insufficient space in the destination buffer. If **STRSAFE_NO_TRUNCATION** is set, see the *dwFlags* parameter for more information. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the function received an invalid input parameter. For more information, see the following paragraph.<br><br>The function returns the STATUS_INVALID_PARAMETER value when:<br><br>* An invalid flag was specified.<br>* The value in *cchDest* is larger than the maximum buffer size.<br>* The destination buffer was already full.<br>* A **NULL** pointer was present without the **STRSAFE_IGNORE_NULLS** flag.<br>* The destination buffer pointer was **NULL**, but the buffer size was not zero.<br>* The destination buffer pointer was **NULL**, or its length was zero, but a nonzero length source string   was present. |

## Remarks

**RtlStringCchCatNExW** and **RtlStringCchCatNExA** should be used instead of the following functions:

- **strncat**
- **wcsncat**

The size, in characters, of the destination buffer is provided to **RtlStringCchCatNExW** and **RtlStringCchCatNExA** to ensure that the functions do not write past the end of the buffer.

**RtlStringCchCatNExW** and **RtlStringCchCatNExA** add to the functionality of [RtlStringCchCatN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatna) by returning a pointer to the end of the destination string, as well as the number of characters left unused in that string. Flags can be passed to the function for additional control.

Use **RtlStringCchCatNExW** to handle Unicode strings and **RtlStringCchCatNExA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

|String data type|String literal|Function|
|--- |--- |--- |
|**WCHAR**|L"string"|**RtlStringCchCatNExW**|
|**char**|"string"|**RtlStringCchCatNExA**|

If *pszSrc* and *pszDest* point to overlapping strings, the behavior of the function is undefined.

Neither *pszSrc* nor *pszDest* can be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set, in which case either or both can be **NULL**. If *pszDest* is **NULL**, *pszSrc* must either be **NULL** or point to an empty string.

For more information about the safe string functions, see [Using safe string functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

- [RtlStringCbCatNEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcbcatnexa)
- [RtlStringCchCatEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatexa)
- [RtlStringCchCatN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchcatna)