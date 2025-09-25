# RtlStringCbLengthW function

## Description

The **RtlStringCbLengthW** and **RtlStringCbLengthA** functions determine the length, in bytes, of a supplied string.

## Parameters

### `psz` [in]

A pointer to a buffer that contains a null-terminated string, the length of which will be checked.

### `cbMax` [in]

The maximum number of bytes allowed in the buffer that is pointed to by *psz*, including the terminating null character.

For Unicode strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(WCHAR).

For ANSI strings, the maximum number of bytes is NTSTRSAFE_MAX_CCH * sizeof(char).

### `pcbLength`

If the caller supplies a non-**NULL** address pointer, the function loads the address with the length, in bytes, of the string that is contained in the buffer. The length does not include the string's terminating null character.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means the string at *psz* was not **NULL**, and the length of the string (including the terminating null character) is less than or equal to *cbMax* characters. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the value in *psz* is **NULL**, *cbMax* is larger than NTSTRSAFE_MAX_CCH * sizeof(TCHAR), or *psz* is longer than *cbMax*. |

## Remarks

**RtlStringCbLengthW** and **RtlStringCbLengthA** should be used instead of **strlen**. Use these functions to ensure that a string is not larger than a given length, in bytes. If that condition is met, **RtlStringCbLengthW** and **RtlStringCbLengthA** return the current length of the string in bytes, not including those bytes used for the terminating null character.

Use **RtlStringCbLengthW** to handle Unicode strings and **RtlStringCbLengthA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCbLengthW** |
| **char** | "string" | **RtlStringCbLengthA** |

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCchLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchlengtha)