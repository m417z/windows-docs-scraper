# NdisUpcaseUnicodeString macro

## Description

The
**NdisUpcaseUnicodeString** function converts a copy of a given Unicode string to upper case and returns
the converted string.

**Note** This function is deprecated for NDIS 6.0 and later.

## Parameters

### `_d`

A pointer to a caller-allocated buffer in which to return the converted string.

### `_s`

A pointer to the source Unicode string to be converted to upper case.

## See also

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)