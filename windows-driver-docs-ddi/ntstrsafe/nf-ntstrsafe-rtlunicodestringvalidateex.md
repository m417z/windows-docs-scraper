# RtlUnicodeStringValidateEx function

## Description

The **RtlUnicodeStringValidateEx** function validates the contents of a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure.

## Parameters

### `SourceString` [in]

Optional. A pointer to a **UNICODE_STRING** structure to be validated. This pointer can be **NULL**, but only if STRSAFE_IGNORE_NULLS is set in *dwFlags*.

### `dwFlags` [in]

The following flag is defined:

#### STRSAFE_IGNORE_NULLS

If this flag is set, the source pointer can be **NULL**. **RtlUnicodeStringValidateEx** treats **NULL** source buffer pointers like empty strings (TEXT("")).

## Return value

**RtlUnicodeStringValidateEx** returns one of the following NTSTATUS values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | This *success* status means that the function completed successfully. |
| **STATUS_INVALID_PARAMETER** | This *error* status means that the function received an invalid input parameter. For more information, see the following list. |

If STRSAFE_IGNORE_NULLS is not set in dwFlags, **RtlUnicodeStringValidateEx** returns the STATUS_INVALID_PARAMETER value when one of the following occurs:

* *SourceString*->**Length** % sizeof(WCHAR) does not equal zero.
* *SourceString*->**MaximumLength** % sizeof(WCHAR) does not equal zero.
* *SourceString*->**Length** is greater than *SourceString*->**MaximumLength**.
* *SourceString*->**MaximumLength** is greater than NTSTRSAFE_UNICODE_STRING_MAX_CCH * sizeof(WCHAR).
* *SourceString*->**Buffer** equals **NULL** but *SourceString*->Length or *SourceString*->**MaximumLength** does not equal zero.
* An invalid flag is specified for *dwFlags*.

For information about how to test NTSTATUS values, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The *SourceString* pointer cannot be **NULL** unless the STRSAFE_IGNORE_NULLS flag is set.

For more information about the safe string functions, see [Using Safe String Functions](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-safe-string-functions).

## See also

[RtlUnicodeStringValidate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringvalidate)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)