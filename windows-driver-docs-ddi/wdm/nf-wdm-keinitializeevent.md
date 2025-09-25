# KeInitializeEvent function

## Description

The **KeInitializeEvent** routine initializes an event object as a synchronization (single waiter) or notification type event and sets it to a signaled or not-signaled state.

## Parameters

### `Event` [out]

Pointer to an event object, for which the caller provides the storage.

### `Type` [in]

Specifies the event type, either **NotificationEvent** or **SynchronizationEvent**.

### `State` [in]

Specifies the initial state of the event. **TRUE** indicates a signaled state.

## Remarks

Storage for an event object must be resident: in the device extension of a driver-created device object, in the controller extension of a driver-created controller object, or in nonpaged pool allocated by the caller. If you allocate the event on the stack, you must specify a **KernelMode** wait when calling [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject), **KeWaitForMutexObject**, or [KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects). During a **KernelMode** wait, the stack containing the event will not be paged out.

Drivers typically use a **NotificationEvent** to wait for an I/O operation to complete. When a notification event is set to the signaled state, all threads that were waiting for the event to be set to the signaled state become eligible for execution. The event remains in the signaled state until a thread calls [KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent) or [KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent) to set the event in the not-signaled state.

A **SynchronizationEvent** is also called an *autoreset* or *autoclearing* event. When such an event is set, a single waiting thread becomes eligible for execution. The kernel automatically resets the event to the not-signaled state each time a wait is satisfied. A driver might use a synchronization event to protect a shared resource that is used in synchronizing the operations of several threads.

For more information about event objects, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeReadStateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereadstateevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForMultipleObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitformultipleobjects)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)