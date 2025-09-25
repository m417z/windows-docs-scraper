# KeClearEvent function

## Description

The **KeClearEvent** routine sets an event to a not-signaled state.

## Parameters

### `Event` [in, out]

Pointer to an initialized dispatcher object of type event for which the caller supplies the storage.

## Remarks

*Event* is set to a not-signaled state, meaning its value is set to zero.

For better performance, use **KeClearEvent** unless the caller uses the value returned by [KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent) to determine what to do next.

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeReadStateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstateevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)