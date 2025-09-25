# IoCreateSynchronizationEvent function

## Description

The **IoCreateSynchronizationEvent** routine creates or opens a named synchronization event for use in serialization of access to hardware between two otherwise unrelated drivers.

## Parameters

### `EventName` [in]

Pointer to a buffer containing a null-terminated Unicode string that names the event.

### `EventHandle` [out]

Pointer to a location in which to return a handle for the event object. In Windows Server 2003 and later versions of Windows, the returned handle is a [kernel handle](https://learn.microsoft.com/windows-hardware/drivers/).

## Return value

**IoCreateSynchronizationEvent** returns a pointer to the created or opened event object or **NULL** if the event object could not be created or opened.

## Remarks

The event object is created if it does not already exist. **IoCreateSynchronizationEvent** sets the state of a new synchronization event to Signaled. If the event object already exists, it is simply opened. The pair of drivers that use a synchronization event call [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) with the PKEVENT pointer returned by this routine.

When a synchronization event is set to the Signaled state, a single thread of execution that was waiting for the event is released, and the event is automatically reset to the Not-Signaled state.

To release the event, a driver calls [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) with the event handle.

Sharing event objects between user mode and kernel mode requires care. There are two main methods for sharing event objects:

* The user-mode application creates the event object and passes a handle to the object to the driver by sending an IOCTL to the driver. The driver must handle the IOCTL in the context of the process that created the event object and must validate the handle by calling [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle). This method is the recommended method for sharing event objects between user and kernel modes.

* The driver creates a named event object in the global `\BaseNamedObjects` object directory. To access a kernel-mode event from user-mode, use the name `Global\\`*Xxx*. Note that security settings can prevent an application from opening the event. The \\BaseNamedObjects object directory is not created until the Microsoft Win32 subsystem initializes, so drivers that are loaded at boot time cannot create event objects in the \\BaseNamedObjects directory in their [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routines

For more information about events, see [Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

## See also

[IoCreateNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatenotificationevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)