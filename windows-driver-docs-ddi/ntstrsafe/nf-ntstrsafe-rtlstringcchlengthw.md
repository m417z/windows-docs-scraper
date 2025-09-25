# RtlStringCchLengthW function

## Description

The **RtlStringCchLengthW** and **RtlStringCchLengthA** functions determine the length, in characters, of a supplied string.

## Parameters

### `psz` [in]

A pointer to a buffer that contains a null-terminated string, the length of which will be checked.

### `cchMax` [in]

The maximum number of characters allowed in the buffer pointed to by *psz*, including the terminating null character. This value cannot exceed NTSTRSAFE_MAX_CCH.

### `pcchLength`

If the caller supplies a non-**NULL** address pointer, the function loads the address with the length, in characters, of the string that is contained in the buffer. The length does not include the string's terminating null character.

## Return value

The function returns one of the NTSTATUS values that are listed in the following table. For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This success status means the string at *psz* was not **NULL**, and the length of the string (including the terminating null character) is less than or equal to *cchMax* characters. |
| **STATUS_INVALID_PARAMETER** | This error status means the value in *psz* is **NULL**, *cchMax* is larger than NTSTRSAFE_MAX_CCH, or *psz* is longer than *cchMax*. |

## Remarks

**RtlStringCchLengthW** and **RtlStringCchLengthA** should be used instead of **strlen**. They are used to ensure that a string is not larger than a given length, in characters. If that condition is met, **RtlStringCchLengthW** and **RtlStringCchLengthA** return the current length of the string in characters, not including the terminating null character.

Use **RtlStringCchLengthW** to handle Unicode strings and **RtlStringCchLengthA** to handle ANSI strings. The form you use depends on your data, as shown in the following table.

| String data type | String literal | Function |
| --- | --- | --- |
| WCHAR | L"string" | **RtlStringCchLengthW** |
| **char** | "string" | **RtlStringCchLengthA** |

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcblengtha)