# KsGateGetStateUnsafe function

## Description

The **KsGateGetStateUnsafe** function returns the state of the given gate (open or closed) in an unsafe manner, that is *without regard to synchronization*.

## Parameters

### `Gate` [in]

A pointer to a [KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate) structure representing the gate for which to return the state.

## Return value

This call returns **TRUE** if the gate is open and **FALSE** if the gate is closed.

## Remarks

Because **KsGateGetStateUnsafe** does not handle synchronization, it is possible to get a result that is not consistent with the state of the gate if the gate is in mid-transition from one state to another at the time of the call.

Consider a situation in which the output of gate A is connected as an input to gate B. A transitions to closed, causing B to transition from open to closed. If, at the same time, another thread calls **KsGateGetStateUnsafe** between the time A closes and the time B closes, the routine still returns that B was open.

**KsGateGetStateUnsafe** returns whether *Gate->Count* is greater than zero. The function does not use any interlocked functions to do this. Thus, the call is performed without regard to synchronization.