# NdisSetEvent function

## Description

The
**NdisSetEvent** function sets a given event to the signaled state if it was not already Signaled.

## Parameters

### `Event` [in]

A pointer to an initialized event object for which the caller provides the storage.

## Remarks

When an event attains the
*signaled* state, it causes waits on the event to be satisfied and any waiters to be dispatched for
execution.

After a call to
**NdisSetEvent**, the event remains in the
*signaled* state until the driver calls the
[NdisResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisresetevent) function.

## See also

[NdisInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisinitializeevent)

[NdisResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisresetevent)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)