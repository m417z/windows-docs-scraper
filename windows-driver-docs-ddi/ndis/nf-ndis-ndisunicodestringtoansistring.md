# NdisUnicodeStringToAnsiString macro

## Description

The
**NdisUnicodeStringToAnsiString** function converts a given counted Unicode string into a counted ANSI
string. The translation conforms to the current system locale information.

## Parameters

### `_as`

A pointer to a caller-allocated buffer in which this function should return the converted ANSI
string.

### `_us`

A pointer to the Unicode string to be converted.

## Remarks

The caller must allocate storage for both the source and destination strings and release these buffers
as soon as the strings are no longer needed. The buffer at
*SourceString* must be at least twice the size of that at
*DestinationString* .

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)