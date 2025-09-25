# NdisGetCurrentSystemTime macro

## Description

The
**NdisGetCurrentSystemTime** function returns the current system time, suitable for setting
timestamps.

## Parameters

### `_pSystemTime` [in]

A pointer to a caller-supplied variable in which this function returns a count of 100-nanosecond
intervals since January 1, 1601.

## Remarks

An NDIS driver might also call
**NdisGetCurrentSystemTime** if it maintains a count of how many packets it receives within any
particular interval to tune its performance dynamically. For example, a miniport driver could call
**NdisGetCurrentSystemTime** for each receive interrupt to determine periods of high network traffic,
when the driver might disable one or more types of interrupts on the NIC and enable a polling
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function to process
receive indications or send requests.

## See also

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)