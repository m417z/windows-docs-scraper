# NdisResetEvent function

## Description

The
**NdisResetEvent** function clears the Signaled state of a given event.

## Parameters

### `Event` [in]

A pointer to an initialized event object for which the caller provided the storage.

## Remarks

**NdisResetEvent** explicitly sets the state of the given event to
*not-signaled*.

When an event is set to the
*signaled* state with the
[NdisSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetevent) function, it remains in that
state until an explicit call to
**NdisResetEvent** occurs. While an event remains in the
*signaled* state, callers of the
[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent) function on that event are
dispatched for execution without waiting.

## See also

[NdisInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeevent)

[NdisSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetevent)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)