# KeSetEvent function

## Description

The **KeSetEvent** routine sets an event object to a signaled state if the event was not already signaled, and returns the previous state of the event object.

## Parameters

### `Event` [in, out]

A pointer to an initialized event object for which the caller provides the storage.

### `Increment` [in]

Specifies the priority increment to be applied if setting the event causes a wait to be satisfied.

### `Wait` [in]

Specifies whether the call to **KeSetEvent** is to be followed immediately by a call to one of the **KeWait*Xxx*** routines. If **TRUE**, the **KeSetEvent** call must be followed by a call to [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects), **KeWaitForMutexObject**, or [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject). For more information, see the following Remarks section.

## Return value

If the previous state of the event object was signaled, a nonzero value is returned.

## Remarks

Calling **KeSetEvent** causes the event to attain a signaled state. If the event is a notification event, the system attempts to satisfy as many waits as possible on the event object. The event remains signaled until a call to [KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent) or [KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent) clears it. If the event is a synchronization event, one wait is satisfied before the system automatically clears the event.

The **KeSetEvent** routine might temporarily raise the IRQL. If the *Wait* parameter is **FALSE**, the routine, before it returns, restores the IRQL to the original value that it had at the start of the call.

If *Wait* = **TRUE**, the routine returns without lowering the IRQL. In this case, the **KeSetEvent** call must be immediately followed by a **KeWait*Xxx*** call. By setting *Wait* = **TRUE**, the caller can prevent an unnecessary context switch from occurring between the **KeSetEvent** call and the **KeWait*Xxx*** call. The **KeWait*Xxx*** routine, before it returns, restores the IRQL to its original value at the start of the **KeSetEvent** call. Although the IRQL disables context switches between the two calls, these calls cannot reliably be used as the start and end of an atomic operation. For example, between these two calls, a thread that is running at the same time on another processor might change the state of the event object or of the target of the wait.

A pageable thread or pageable driver routine that runs at IRQL = PASSIVE_LEVEL should never call **KeSetEvent** with the *Wait* parameter set to TRUE. Such a call causes a fatal page fault if the caller happens to be paged out between the calls to **KeSetEvent** and **KeWait*Xxx***.

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

If *Wait* is set to **FALSE**, the caller can be running at IRQL <= DISPATCH_LEVEL. Otherwise, callers of **KeSetEvent** must be running at IRQL <= APC_LEVEL and in a nonarbitrary thread context.

## See also

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeReadStateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstateevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[Specifying Priority Boosts When Completing I/O Requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-priority-boosts-when-completing-i-o-requests)