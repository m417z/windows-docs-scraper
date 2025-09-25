# WdmlibRtlInitUnicodeStringEx function

## Description

The **WdmlibRtlInitUnicodeStringEx** function initializes a counted string of Unicode characters.

## Parameters

### `DestinationString` [out]

A pointer to the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure to be initialized.

### `SourceString` [in, optional]

A pointer to a null-terminated wide-character string. This string is used to initialize the counted string pointed to by *DestinationString*.

## Return value

**WdmlibRtlInitUnicodeStringEx** returns STATUS_SUCCESS if successful, otherwise the method may return other NTSTATUS values.

## Remarks

The routine copies the *SourceString* pointer value to the **Buffer** member of the [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure pointed to by *DestinationString*. The **Length** member of this structure is set to the length, in bytes, of the source string, excluding the terminating null. The **MaximumLength** member of the structure is set to the length, in bytes, of the source string, including the terminating null. If *SourceString* is **NULL**, **Length** and **MaximumLength** are both set to zero.

**WdmlibRtlInitUnicodeStringEx** does not alter the source string pointed to by *SourceString*.

> [!NOTE]
> If the source string is longer than MAX_USTRING - 1 bytes (where MAX_USTRING = 0xfffe), **WdmlibRtlInitUnicodeStringEx** sets the **Length** member of the **UNICODE_STRING** structure pointed to by *DestinationString* to MAX_USTRING - 2, and sets the **MaximumLength** member of this structure to MAX_USTRING. In this case, the **Length** and **MaximumLength** values misrepresent the length of the null-terminated source string, and relying on the accuracy of these values is potentially dangerous.

Callers of **WdmlibRtlInitUnicodeStringEx** can be running at IRQL <= DISPATCH_LEVEL if the *DestinationString* buffer is nonpageable. Usually, callers run at IRQL = PASSIVE_LEVEL because most other **Rtl*Xxx*String** routines cannot be called at IRQL > PASSIVE_LEVEL.

## See also

- [RtlUnicodeStringInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinit)
- [RtlUnicodeStringInitEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntstrsafe/nf-ntstrsafe-rtlunicodestringinitex)
- [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)