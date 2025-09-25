# _IRP structure

## Description

The **IRP** structure is a partially opaque structure that represents an *I/O request packet*. Undocumented members of the **IRP** structure are reserved, used only by the I/O manager or in some cases, by file system drivers (FSDs).

## Members

### `Type`

Reserved for internal system use.

### `Size`

Reserved for internal system use.

### `MdlAddress`

Pointer to an MDL describing a user buffer, if the driver is using direct I/O, and the IRP major function code is one of the following:

- **IRP_MJ_READ**

 The MDL describes an empty buffer that the device or driver fills in.

- **IRP_MJ_WRITE**

 The MDL describes a buffer that contains data for the device or driver.

- **IRP_MJ_DEVICE_CONTROL** or **IRP_MJ_INTERNAL_DEVICE_CONTROL**

 If the IOCTL code specifies the METHOD_IN_DIRECT transfer type, the MDL describes a buffer that contains data for the device or driver.

If the IOCTL code specifies the METHOD_OUT_DIRECT transfer type, the MDL describes an empty buffer that the device or driver fills in.

For more information about the buffers that are associated with METHOD_IN_DIRECT and METHOD_OUT_DIRECT transfer types in IOCTL codes, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

If the driver is not using direct I/O, this pointer is **NULL**.

### `Flags`

File system drivers use this field, which is read-only for all drivers. Network and, possibly, highest-level device drivers also might read this field. This field is set either to zero or to the bitwise-OR of one or more of the following system-defined flag bits:

- IRP_NOCACHE
- IRP_PAGING_IO
- IRP_MOUNT_COMPLETION
- IRP_SYNCHRONOUS_API
- IRP_ASSOCIATED_IRP
- IRP_BUFFERED_IO
- IRP_DEALLOCATE_BUFFER
- IRP_INPUT_OPERATION
- IRP_SYNCHRONOUS_PAGING_IO
- IRP_CREATE_OPERATION
- IRP_READ_OPERATION
- IRP_WRITE_OPERATION
- IRP_CLOSE_OPERATION
- IRP_DEFER_IO_COMPLETION
- IRP_OB_QUERY_NAME
- IRP_HOLD_DEVICE_QUEUE
- IRP_UM_DRIVER_INITIATED_IO

### `AssociatedIrp`

Reserved for internal system use.

### `AssociatedIrp.MasterIrp`

Pointer to the master IRP in an IRP that was created by a highest-level driver's call to [IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp).

### `AssociatedIrp.IrpCount`

Reserved for internal system use.

### `AssociatedIrp.SystemBuffer`

Pointer to a system-space buffer.

If the driver is using buffered I/O, the buffer's purpose is determined by the IRP major function code, as follows:

- **SystemBuffer.IRP_MJ_READ**

 The buffer receives data from the device or driver. The buffer's length is specified by **Parameters.Read.Length** in the driver's [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure.

- **SystemBuffer.IRP_MJ_WRITE**

 The buffer supplies data for the device or driver. The buffer's length is specified by **Parameters.Write.Length** in the driver's **IO_STACK_LOCATION** structure.

- **SystemBuffer.IRP_MJ_DEVICE_CONTROL** or **IRP_MJ_INTERNAL_DEVICE_CONTROL**

 The buffer represents both the input and output buffers that are supplied to **DeviceIoControl** and **IoBuildDeviceIoControlRequest**. Output data overwrites input data.

For input, the buffer's length is specified by **Parameters.DeviceIoControl.InputBufferLength** in the driver's **IO_STACK_LOCATION** structure.

For output, the buffer's length is specified by **Parameters.DeviceIoControl.OutputBufferLength** in the driver's **IO_STACK_LOCATION** structure.

For more information, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

The buffer represents the input buffer that is supplied to **DeviceIoControl** and **IoBuildDeviceIoControlRequest**.

The buffer's length is specified by **Parameters.DeviceIoControl.InputBufferLength** in the driver's **IO_STACK_LOCATION** structure.

For more information, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

If the driver is using direct I/O, the buffer's purpose is determined by the IRP major function code, as follows:

### `ThreadListEntry`

Reserved for internal system use.

### `IoStatus`

Contains the [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure in which a driver stores status and information before calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest).

### `RequestorMode`

Indicates the execution mode of the original requester of the operation, one of **UserMode** or **KernelMode**.

### `PendingReturned`

If set to **TRUE**, a driver has marked the IRP pending. Each [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine should check the value of this flag. If the flag is **TRUE**, and if the IoCompletion routine will not return STATUS_MORE_PROCESSING_REQUIRED, the routine should call [IoMarkIrpPending](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iomarkirppending) to propagate the pending status to drivers above it in the device stack.

### `StackCount`

Reserved for internal system use.

### `CurrentLocation`

Reserved for internal system use.

### `Cancel`

If set to **TRUE**, the IRP either is or should be canceled.

### `CancelIrql`

Contains the IRQL at which a driver is running when [IoAcquireCancelSpinLock](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff548196(v=vs.85)) is called.

### `ApcEnvironment`

Reserved for internal system use.

### `AllocationFlags`

Reserved for internal system use.

### `UserIosb`

Reserved for internal system use.

### `IoRingContext`

Reserved for internal system use.

### `UserEvent`

Reserved for internal system use.

### `Overlay`

Reserved for internal system use.

### `Overlay.AsynchronousParameters`

Reserved for internal system use.

### `Overlay.AsynchronousParameters.UserApcRoutine`

Reserved for internal system use.

### `Overlay.AsynchronousParameters.IssuingProcess`

Reserved for internal system use.

### `Overlay.AsynchronousParameters.UserApcContext`

Reserved for internal system use.

### `Overlay.AsynchronousParameters.IoRing`

Reserved for internal system use.

### `Overlay.AllocationSize`

Reserved for internal system use.

### `CancelRoutine`

Contains the entry point for a driver-supplied [Cancel](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterextensionrequest-cancel) routine to be called if the IRP is canceled. **NULL** indicates that the IRP is not currently cancelable.

### `UserBuffer`

Contains the address of an output buffer if both of the following conditions apply:

- The major function code in the I/O stack location is [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) or [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control).

- The I/O control code was defined with METHOD_NEITHER or METHOD_BUFFERED.

For METHOD_BUFFERED, the driver should use the buffer pointed to by **Irp->AssociatedIrp.SystemBuffer** as the output buffer. When the driver completes the request, the I/O manager copies the contents of this buffer to the output buffer that is pointed to by **Irp->UserBuffer**. The driver should not write directly to the buffer pointed to by **Irp->UserBuffer**. For more information, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

### `Tail`

Reserved for internal system use.

### `Tail.Overlay`

Reserved for internal system use.

### `Tail.Overlay.DeviceQueueEntry`

If IRPs are queued in the device queue associated with the driver's device object, this field links IRPs in the device queue. These links can be used only while the driver is processing the IRP.

### `Tail.Overlay.DriverContext`

If IRPs are not queued in the device queue associated with the driver's device object, this field can be used by the driver to store up to four pointers. This field can be used only while the driver owns the IRP.

### `Tail.Overlay.Thread`

A pointer to the caller's thread control block (TCB). For requests that originate in user-mode, the I/O manager always sets this field to point to the TCB of the thread that issued the request.

### `Tail.Overlay.AuxiliaryBuffer`

Reserved for internal system use.

### `Tail.Overlay.ListEntry`

If a driver manages its own internal queues of IRPs, it uses this field to link one IRP to the next. These links can be used only while the driver is holding the IRP in its queue or is processing the IRP.

### `Tail.Overlay.CurrentStackLocation`

Reserved for internal system use.

### `Tail.Overlay.PacketType`

Reserved for internal system use.

### `Tail.Overlay.OriginalFileObject`

Reserved for internal system use.

### `Tail.Apc`

Reserved for internal system use.

### `Tail.CompletionKey`

Reserved for internal system use.

## Remarks

Undocumented members of the IRP structure are reserved, used only by the I/O manager or in some cases, by file system drivers (FSDs).

An IRP is the basic I/O manager structure used to communicate with drivers and to allow drivers to communicate with each other. A packet consists of two different parts:

- *Header*, or *fixed part of the packet*— This is used by the I/O manager to store information about the original request, such as the caller's device-independent parameters, the address of the device object upon which a file is open, and so on. It is also used by drivers to store information such as the final status of the request.

- *I/O stack locations* — Following the header is a set of [I/O stack locations](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations), one per driver in the chain of layered drivers for which the request is bound. Each stack location contains the parameters, function codes, and context used by the corresponding driver to determine what it is supposed to be doing. For more information, see the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure.

While a higher-level driver might check the value of the **Cancel** Boolean in an IRP, that driver cannot assume the IRP will be completed with STATUS_CANCELLED by a lower-level driver even if the value is **TRUE**.

## See also

- [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)
- [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)
- [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)
- [IoGetCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentirpstacklocation)
- [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation)
- [IoSetCancelRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine)
- [IoSetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetnextirpstacklocation)