# NdisInitUnicodeString macro

## Description

The
**NdisInitUnicodeString** function initializes a counted Unicode string.

## Parameters

### `_us`

A pointer to a caller-allocated NDIS_STRING type in which
**NdisInitUnicodeString** should store the counted Unicode string. For Windows 2000 and later, NDIS
defines the NDIS_STRING type as a
[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) type.

### `s`

A pointer to a null-terminated string with which to initialize the counted string.

## Remarks

The
*DestinationString* is initialized to point to the
*SourceString* . The
**Length** and
**MaximumLength** members of NDIS_STRING for the
*DestinationString* are initialized to the length of the string at
*SourceString*. If
*SourceString* is **NULL**, the length is zero.

Callers of
**NdisInitUnicodeString** must be running at IRQL <= DISPATCH_LEVEL if the
*DestinationString* buffer is allocated from nonpaged memory. Usually, callers are running at IRQL =
PASSIVE_LEVEL during driver initialization.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisansistringtounicodestring)

[NdisInitAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitansistring)

[NdisInitializeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializestring)

[NdisUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisunicodestringtoansistring)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)