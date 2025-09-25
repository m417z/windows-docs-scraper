# IoCreateNotificationEvent function

## Description

The **IoCreateNotificationEvent** routine creates or opens a named notification event used to notify one or more threads of execution that an event has occurred.

## Parameters

### `EventName` [in]

Pointer to a buffer containing a null-terminated Unicode string that names the event.

### `EventHandle` [out]

Pointer to a location in which to return a kernel handle for the event object.

## Return value

**IoCreateNotificationEvent** returns a pointer to the created or opened event object or **NULL** if the event object could not be created or opened.

## Remarks

If the event object does not already exist, **IoCreateNotificationEvent** creates and opens it, and sets its state to Signaled.

If the event object already exists, **IoCreateNotificationEvent** just opens the event object.

Both notification events and synchronization events are used to coordinate execution. However, while a synchronization event resets itself, a notification event remains in the Signaled state until the driver calls [**KeClearEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent) or [**KeResetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent).

To synchronize on a notification event:

1. Open the notification event with **IoCreateNotificationEvent**. Identify the event with the *EventName* string.
2. Wait for the event to be signaled by calling [**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) with the PKEVENT returned by **IoCreateNotificationEvent**. More than one thread of execution can wait for a given notification event. To poll instead of stall, specify a *Timeout* of zero to **KeWaitForSingleObject**.
3. Close the handle to the notification event with [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) when access to the event is no longer needed.

There are two main methods for sharing event objects:

* The user-mode application creates the event object and passes a handle to the object to the driver by sending an IOCTL to the driver. The driver must handle the IOCTL in the context of the process that created the event object and must validate the handle by calling [**ObReferenceObjectByHandle**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle). This method is the recommended method for sharing event objects between user and kernel modes.

* The driver creates a named event object in the global `\BaseNamedObjects` object directory. To access a kernel-mode event from user-mode, use the name `Global\\`*Xxx*. Note that security settings can prevent an application from opening the event. The `\\BaseNamedObjects` object directory is not created until the Microsoft Win32 subsystem initializes, so drivers that are loaded at boot time cannot create event objects in the `\\BaseNamedObjects` directory in their [*DriverEntry*](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routines.

For more information about events, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[IoCreateSynchronizationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesynchronizationevent)

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)