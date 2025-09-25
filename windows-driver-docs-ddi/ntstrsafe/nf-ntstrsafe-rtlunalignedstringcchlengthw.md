# RtlUnalignedStringCchLengthW function

## Description

The **RtlUnalignedStringCchLengthW** function is a version of the [RtlStringCchLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchlengtha) function that accepts an unaligned pointer to a string of Unicode characters.

## Parameters

### `psz` [in]

Supplies a pointer to a buffer that contains a null-terminated string whose length **RtlUnalignedStringCchLengthW** will check.

### `cchMax` [in]

Supplies the maximum number of characters that are allowed in the buffer that *psz* points to, including the terminating NULL character. This value cannot exceed NTSTRSAFE_MAX_CCH.

### `pcchLength` [out, optional]

Optional. If the caller supplies a non-**NULL** address pointer, the function loads the address with the length, in characters, of the string that is contained in the buffer that *psz* points to. The length does not include the string's terminating NULL character.

## Return value

**RtlUnalignedStringCchLengthW** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means the string that the *psz* parameter was not **NULL**, and the length of the string (including the terminating NULL character) was less than or equal to *cchMax* characters. |
| **STATUS_INVALID_PARAMETER** | This *error* status means the value in *psz* is **NULL**, *cchMax* is larger than NTSTRSAFE_MAX_CCH, or *psz* is longer than *cchMax*. |

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnalignedStringCchLengthW** function is available for processor architectures, such as Itanium-based and x64-based, that cause alignment exceptions when software attempts to access unaligned data. On those processors, you can use **RtlUnalignedStringCchLengthW** instead of [RtlStringCchLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchlengtha) to avoid alignment exceptions. (For processors that do not cause alignment exceptions, **RtlUnalignedStringCchLengthW** is equivalent to **RtlStringCchLength**.)

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlStringCchLength](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlstringcchlengtha)