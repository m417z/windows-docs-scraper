# IOCTL_PMI_REGISTER_EVENT_NOTIFY IOCTL

## Description

The **IOCTL_PMI_REGISTER_EVENT_NOTIFY** request registers the IOCTL initiator to be notified about a power meter event. When the event occurs, the Power Meter Interface (PMI) completes the IOCTL request and returns information about the event.

## Parameters

### Major code

### Input buffer

The **AssociatedIrp.SystemBuffer** member of the I/O request packet (IRP) points to an initiator-allocated input buffer that contains a [PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event) structure.

### Input buffer length

The **Parameters.DeviceIoControl.InputBufferLength** member of the IRP's current I/O stack location ([IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)) is set to the size in bytes of the input buffer that is pointed to by the **AssociatedIrp.SystemBuffer** member. This size must be greater than or equal to **sizeof**(**PMI_EVENT**) or the request will fail with an error status of STATUS_BUFFER_TOO_SMALL.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** member is set to the size, in bytes, of a [PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event) structure.

The **Status** member is set to one of the following values:

**STATUS_BUFFER_TOO_SMALL**

The **Parameters.DeviceIoControl.OutputBufferLength** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) is less than the size, in bytes, of a [PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event) structure.

**STATUS_PENDING**

The WDM driver that supports the PMI interface has put the IOCTL request in a queue and will complete it after a PMI event occurs.

**STATUS_SUCCESS**

The WDM driver that supports the PMI interface has completed the IOCTL request successfully.

## Remarks

PMI creates an event notification queue for each initiator that opens the device instance for a power meter by using the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function. A separate queue is created for each caller's connection to a device instance. The following points apply to the event notification queue:

* When PMI creates the event notification queue, the queue is empty. After the queue is created, PMI sends events to the caller after the caller has registered for event notification by using the **IOCTL_PMI_REGISTER_EVENT_NOTIFY** request.
* If the event notification queue is empty when the caller registers, the **IOCTL_PMI_REGISTER_EVENT_NOTIFY** request remains pending until either an event occurs or the device instance connection is broken through the **CloseFile** function.
* After the event notification queue is created, the queue will contain unsent events for the caller. This prevents callers from missing events during the interval between when the driver processes one event and the caller registers for another. If there are events in the caller's queue, they are sent immediately after the caller registers by using an **IOCTL_PMI_REGISTER_EVENT_NOTIFY** request.

When PMI sends a power meter event to the caller, it completes the **IOCTL_PMI_REGISTER_EVENT_NOTIFY** request. The data that describes the event is contained within the [PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event) structure in the output buffer that is referenced by the **MdlAddress** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp). The **EventType** member of this structure contains information about the power meter event's type. For example, if **EventType** is set to **PmiConfigurationChangedEvent**, the power meter's configuration has changed. In this case, the caller can query the power meter's new configuration by using an [IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration) request.

For more information about the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) and **CloseFile** functions, refer to the Windows SDK documentation.

## See also

[IOCTL_PMI_GET_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_configuration)

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[PMI_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ns-pmi-_pmi_event)