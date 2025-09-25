# NdisEqualString macro

## Description

The
**NdisEqualString** function compares two strings, in the OS-default character set, to determine whether
they are equal.

## Parameters

### `_String1` [in]

A pointer to an NDIS_STRING type that describes the first string.

### `_String2` [in]

A pointer to an NDIS_STRING type that describes the second string.

### `_CaseInsensitive` [in]

A boolean value that is **TRUE** if case should be ignored when doing the comparison. Otherwise, it is
**FALSE**.

## Remarks

Starting with Windows 2000, a string of type NDIS_STRING is a counted, null-terminated Unicode string.
That is, NDIS defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[RtlInitString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitstring)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)