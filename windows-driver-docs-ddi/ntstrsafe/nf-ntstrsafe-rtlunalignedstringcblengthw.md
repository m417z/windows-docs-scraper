# RtlUnalignedStringCbLengthW function

## Description

The **RtlUnalignedStringCbLengthW** function is a version of the [RtlStringCbLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcblengtha) function that accepts an unaligned pointer to a string of Unicode characters.

## Parameters

### `psz` [in]

Supplies a pointer to a buffer that contains a null-terminated string whose length **RtlUnalignedStringCbLengthW** will check.

### `cbMax` [in]

Supplies the maximum number of bytes that are allowed in the buffer that *psz* points to, including the terminating NULL character. This value cannot exceed NTSTRSAFE_MAX_CCH * sizeof(WCHAR).

### `pcbLength` [out, optional]

Optional. If the caller supplies a non-**NULL** address pointer, the function loads the address with the length, in bytes, of the string that is contained in the buffer that *psz* points to. The length does not include the string's terminating NULL character.

## Return value

**RtlUnalignedStringCbLengthW** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means the string that the *psz* parameter specified was not **NULL**, and the length of the string (including the terminating NULL character) was less than or equal to *cbMax* bytes. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the value in *psz* is **NULL**, *cbMax* is larger than NTSTRSAFE_MAX_CCH * sizeof(WCHAR, or *psz* is longer than *cbMax*. |

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnalignedStringCbLengthW** function is available for processor architectures, such as Itanium-based and x64-based, that cause alignment exceptions when software attempts to access unaligned data. On those processors, you can use **RtlUnalignedStringCbLengthW** instead of the [RtlStringCbLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcblengtha) function to avoid alignment exceptions. (For processors that do not cause alignment exceptions, **RtlUnalignedStringCbLengthW** is equivalent to **RtlStringCbLength**.)

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCbLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcblengtha)