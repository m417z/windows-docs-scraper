# KeReadStateEvent function

## Description

The **KeReadStateEvent** routine returns the current state, signaled or not-signaled, of an event object.

## Parameters

### `Event` [in]

A pointer to an initialized event object for which the caller provides the storage.

## Return value

If the event object is currently set to a signaled state, a nonzero value is returned. Otherwise, zero is returned.

## Remarks

This routine provides an efficient way to poll the signal state of an event. **KeReadStateEvent** reads the state of the event without synchronizing its access to the event. Do not assume that accesses of an event state by **KeReadStateEvent** are mutually exclusive of accesses by routines, such as [KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent) and [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject), that do synchronize their access to the event state.

It is also possible to read the state of an event from a driver's interrupt service routine at DIRQL, if the following conditions are met: the driver's event object is resident (probably in its device extension), and any other function that accesses the event synchronizes its access with the ISR.

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)