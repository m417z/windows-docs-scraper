# RtlInitUTF8String function

## Description

The **RtlInitUTF8String** function initializes a counted string of UTF-8 characters.

## Parameters

### `DestinationString`

A pointer to **UTF8_STRING** (**STRING**) structure to be initialized.

### `SourceString`

Optional pointer to a null-terminated character string. This string is used to initialize the counted string pointed to by *DestinationString*.

## Return value

None

## Remarks

The routine copies the *SourceString* pointer value to the **Buffer** member of the [**UTF8_STRING**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string) structure pointed to by *DestinationString*. The **Length** member of this structure is set to the length, in bytes, of the source string, excluding the terminating null. The **MaximumLength** member of the structure is set to the length, in bytes, of the source string, including the terminating null. If *SourceString* is **NULL**, **Length** and **MaximumLength** are both set to zero.

**RtlInitUTF8String** does not alter the source string pointed to by *SourceString*.

## See also

[**RtlInitAnsiString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitansistring)