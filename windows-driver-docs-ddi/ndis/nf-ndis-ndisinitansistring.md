# NdisInitAnsiString macro

## Description

The
**NdisInitAnsiString** function initializes a counted ANSI string.

## Parameters

### `_as`

A pointer to a caller-allocated buffer in which this function should store the counted ANSI
string.

### `s`

A pointer to a null-terminated string with which to initialize the counted string.

## Remarks

The
*DestinationString* is initialized to point to the
*SourceString*. The length and maximum length for the
*DestinationString* are initialized to the length of the string at
*SourceString*. If
*SourceString* is **NULL**, the length is zero.

Callers of
**NdisInitAnsiString** must be running at IRQL <= DISPATCH_LEVEL if the
*DestinationString* buffer is allocated from nonpaged memory. Usually, callers are running at IRQL =
PASSIVE_LEVEL during driver initialization.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[RtlAnsiStringToUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlansistringtounicodestring)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[RtlUnicodeStringToAnsiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlunicodestringtoansistring)