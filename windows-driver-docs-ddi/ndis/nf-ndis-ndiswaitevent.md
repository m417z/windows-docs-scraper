# NdisWaitEvent function

## Description

The
**NdisWaitEvent** function puts the caller into a wait state until the given event is set to the Signaled
state or the wait times out.

## Parameters

### `Event` [in]

A pointer to an initialized event object for which the caller provides the storage.

### `MsToWait` [in]

The number of milliseconds the caller will wait if the event is not set to the
*signaled* state within that interval. A value of zero specifies that the caller will wait for the
event indefinitely.

## Return value

**NdisWaitEvent** returns **TRUE** if the event is in the
*signaled* state when the wait is satisfied.

## Remarks

**NdisWaitEvent** returns control to its caller when the given event is signaled or the specified
*MsToWait* interval expires, whichever is sooner. If the event is currently in the
*signaled* state when this call occurs,
**NdisWaitEvent** returns control immediately.

A miniport driver typically calls
**NdisWaitEvent** from its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) and
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) functions. A protocol
driver typically calls
**NdisWaitEvent** from its
[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex) and
[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex) functions.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeevent)

[NdisResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisresetevent)

[NdisSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetevent)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)

[ProtocolUnbindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_unbind_adapter_ex)