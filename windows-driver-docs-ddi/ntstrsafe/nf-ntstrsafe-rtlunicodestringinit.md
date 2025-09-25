# RtlUnicodeStringInit function

## Description

The **RtlUnicodeStringInit** function initializes a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `DestinationString` [out]

A pointer to a **UNICODE_STRING** structure to be initialized. The *pszSrc* pointer is copied into the *DestinationString* parameter's **UNICODE_STRING** structure. The maximum number of characters in the string that *pszSrc* points to is NTSTRSAFE_UNICODE_STRING_MAX_CCH.

### `pszSrc` [in, optional]

Optional. A pointer to a null-terminated string constant. This string pointer will be copied to the **Buffer** member of the **UNICODE_STRING** structure pointed to by the *DestinationString* parameter. This string pointer can be **NULL**.

## Return value

**RtlUnicodeStringInit** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that source data was present, the string was copied without truncation, and the resultant destination buffer is null-terminated. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringInit** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* The length of the string that the *pszSrc* parameter points to is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH characters.
* The *DestinationString* pointer is **NULL**, but the *pszSrc* pointer is not **NULL**.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The **RtlUnicodeStringInit** function does the following:

* Sets the **Length** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that is pointed to by the *pszSrc* parameter to the length, in bytes, of the string that the *pszSrc* parameter points to.
* Sets the **MaximumLength** member of the **UNICODE_STRING** structure to the length, in bytes, of the string that the *pszSrc* parameter points to plus 2 bytes.
* Sets the **Buffer** member of the **UNICODE_STRING** structure to the address that the *pszSrc* parameter specifies.

The *DestinationString* pointer should not be **NULL**. If you need to specify **NULL** *DestinationString* pointer values, use the [RtlUnicodeStringInitEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinitex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringInitEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinitex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)