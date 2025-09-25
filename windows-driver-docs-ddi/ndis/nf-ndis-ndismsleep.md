# NdisMSleep function

## Description

The
**NdisMSleep** function delays execution of the caller for a given interval in microseconds.

## Parameters

### `MicrosecondsToSleep` [in]

The number of microseconds to delay.

## Remarks

For the given time in the
*MicrosecondsToSleep* parameter, the caller's thread of execution is put into a wait state, thereby
allowing other threads to get work done on the current processor. When the given interval expires, the
caller of
**NdisMSleep** resumes execution.

An NDIS driver should always call
**NdisMSleep** in preference to the
[NdisStallExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstallexecution) function unless the
driver is running at IRQL >= DISPATCH_LEVEL.
**NdisMSleep** can accept a larger delay interval than
**NdisStallExecution**, which should
never be called with an interval greater than 50 microseconds. Do not call **NdisMSleep** with a timeout of more than 30,000,000 microseconds (that is, 30 seconds or half a minute).

Miniport drivers can call
**NdisMSleep** from their
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) and,
possibly,
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) functions when either
function must wait for state changes to occur in the NIC before that function continues its
operations.

Both
**NdisMSleep** and
**NdisStallExecution** allow a miniport driver to specify a delay consistently and independently of the
clock speed of the host CPU. Neither function involves a timer object such as those that are used by the
[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject) function. The
resolution of the host system clock varies, so very short delays can take slightly longer than the delay
time that the caller of
**NdisMSleep** or
**NdisStallExecution** specified.

## See also

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisSetTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissettimerobject)

[NdisStallExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstallexecution)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)