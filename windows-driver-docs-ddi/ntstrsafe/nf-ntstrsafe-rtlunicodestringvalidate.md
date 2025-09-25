# RtlUnicodeStringValidate function

## Description

The **RtlUnicodeStringValidate** function validates the contents of a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `SourceString` [in]

A pointer to a **UNICODE_STRING** structure to be validated.

## Return value

**RtlUnicodeStringValidate** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that the function completed successfully. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

**RtlUnicodeStringValidate** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* *SourceString*->**Length** % sizeof(WCHAR) does not equal zero.
* *SourceString*->**MaximumLength** % sizeof(WCHAR) does not equal zero.
* *SourceString*->**Length** is greater than *SourceString*->**MaximumLength**.
* *SourceString*->**MaximumLength** is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).
* *SourceString*->**Buffer** equals **NULL** but *SourceString*->**Length** or *SourceString*->**MaximumLength** does not equal zero.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The *SourceString* pointer cannot be **NULL**. If you need to specify a **NULL** pointer value, use the [RtlUnicodeStringValidateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringvalidateex) function.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringValidateEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringvalidateex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)