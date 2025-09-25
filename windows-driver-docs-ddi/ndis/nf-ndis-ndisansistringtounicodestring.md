# NdisAnsiStringToUnicodeString macro

## Description

The
**NdisAnsiStringToUnicodeString** function converts a given counted ANSI string into a counted Unicode
string. The translation conforms to the current system locale information.

## Parameters

### `_us`

A pointer to a caller-allocated buffer in which this function should return the converted Unicode
string.

### `_as`

A pointer to the ANSI string to be converted.

## Remarks

The caller must allocate storage for both the source and destination strings and release these buffers
as soon as the strings are no longer needed. The buffer at
*DestinationString* must be at least twice the size of the buffer at
*SourceString* .

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)