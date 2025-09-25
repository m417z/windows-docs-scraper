# RtlInitUTF8StringEx function (wdm.h)

## Description

The **RtlInitUTF8StringEx** routine initializes a counted string of UTF-8 characters.

## Parameters

### `DestinationString`

A pointer to the **UTF8_STRING** structure to be initialized. The Ntdef.h header file defines this structure to be identical to the [**STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure.

### `SourceString`

A pointer to a null-terminated character string. This string is used to initialize the counted string pointed to by *DestinationString*.

## Return value

Returns STATUS_NAME_TOO_LONG if the SourceString is too long. Otherwise, this routine returns STATUS_SUCCESS.

## Remarks

The routine copies the *SourceString* pointer value to the **Buffer** member of the **UTF8_STRING** structure pointed to by *DestinationString*. The **Length** member of this structure is set to the length, in bytes, of the source string, excluding the terminating null. The **MaximumLength** member of the structure is set to the length, in bytes, of the source string, including the terminating null. If *SourceString* is **NULL**, **Length** and **MaximumLength** are both set to zero.

**RtlInitUTF8StringEx** does not alter the source string pointed to by *SourceString*.

Callers of **RtlInitUTF8StringEx** can be running at IRQL <= DISPATCH_LEVEL if the *DestinationString* buffer is nonpageable. Usually, callers run at IRQL = PASSIVE_LEVEL because most other **Rtl*Xxx*String** routines cannot be called at IRQL > PASSIVE_LEVEL.

## See also

[**RtlInitAnsiString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitansistring)