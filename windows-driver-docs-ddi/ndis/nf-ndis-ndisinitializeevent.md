# NdisInitializeEvent function

## Description

The
**NdisInitializeEvent** function sets up an event object during driver initialization to be used
subsequently as a synchronization mechanism.

## Parameters

### `Event` [out]

A pointer to caller-supplied storage for the event object, which is opaque to drivers.

## Remarks

The
**NdisInitializeEvent** function creates an event object that has an event type of
**NotificationEvent** and an initial state of
*not-signaled*. For more information about notification events, see
[Defining and Using an Event
Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-and-using-an-event-object).

The
*Event* pointer passed to
**NdisInitializeEvent** is a required parameter to all other
**Ndis*Xxx*Event** functions.

While driver functions that must run at IRQL <= DISPATCH_LEVEL can call the
[NdisSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetevent) and
[NdisResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisresetevent) functions ,calling
**NdisWaitEvent** from any IRQL > PASSIVE_LEVEL is a fatal error.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisresetevent)

[NdisSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetevent)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)