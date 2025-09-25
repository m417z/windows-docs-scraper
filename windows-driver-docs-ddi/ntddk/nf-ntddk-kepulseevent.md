# KePulseEvent function

## Description

The **KePulseEvent** routine atomically sets an event object to a signaled state, attempts to satisfy as many waits as possible, and then resets the event object to a not-signaled state.

## Parameters

### `Event` [in, out]

A pointer to a dispatcher object of type KEVENT.

### `Increment` [in]

Specifies a boost to apply to the priority of threads which are readied as a result of pulsing the event. Typically set to zero but can be set to one.

### `Wait` [in]

Specifies a Boolean value that signifies whether the call to **KePulseEvent** will be immediately followed by a call to one of the **KeWait*Xxx*** routines. If **TRUE**, the **KePulseEvent** call is immediately followed by a call to [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects), **KeWaitForMutexObject**, or [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject). For more information, see the following Remarks section.

## Return value

The previous signal state of the event object.

## Remarks

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

The **KePulseEvent** routine might temporarily raise the IRQL. If the *Wait* parameter is **FALSE**, the routine, before it returns, restores the IRQL to the original value that it had at the start of the call.

If *Wait* = **TRUE**, the routine returns without lowering the IRQL. In this case, the **KePulseEvent** call must be immediately followed by a **KeWait*Xxx*** call. By setting *Wait* = **TRUE**, the caller can prevent an unnecessary context switch from occurring between the **KePulseEvent** call and the **KeWait*Xxx*** call. The **KeWait*Xxx*** routine, before it returns, restores the IRQL to its original value at the start of the **KePulseEvent** call. Although the IRQL disables context switches between the two calls, these calls cannot reliably be used as the start and end of an atomic operation. For example, between these two calls, a thread that is running at the same time on another processor might change the state of the event object or of the target of the wait.

If the caller is executing at IRQL = DISPATCH_LEVEL or in an arbitrary thread context, the *Timeout* parameter to **KeWait*Xxx*** must be zero.

> [!WARNING]
> If a thread waiting for *Event* is currently running a kernel APC, then, when **KePulseEvent** is called, this thread's wait is not satisfied. After the kernel APC completes, the thread remains in the wait state.

## See also

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeReadStateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstateevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)