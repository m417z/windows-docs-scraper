# KeResetEvent function

## Description

The **KeResetEvent** routine resets a specified event object to a not-signaled state and returns the previous state of that event object.

## Parameters

### `Event` [in, out]

A pointer to an initialized dispatcher object of type event for which the caller provides the storage.

## Return value

**KeResetEvent** returns a value that indicates the previous state of the specified *Event*, which is nonzero for a signaled state.

## Remarks

*Event* is reset to a not-signaled state, meaning that its value is set to zero.

Unless the caller requires the value that is returned by **KeResetEvent**, using the [KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent) routine is a faster way to set an event object to a not-signaled state.

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeReadStateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstateevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)