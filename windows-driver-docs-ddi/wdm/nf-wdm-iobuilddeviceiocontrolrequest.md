# IoBuildDeviceIoControlRequest function

## Description

The **IoBuildDeviceIoControlRequest** routine allocates and sets up an IRP for a synchronously processed device control request.

## Parameters

### `IoControlCode` [in]

Supplies the I/O control code ([IOCTL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)) to be used in the request. For information about device type-specific I/O control codes, see device type-specific sections in the Windows Driver Kit (WDK).

### `DeviceObject` [in]

Supplies a pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure for the next-lower driver's device object, which represents the target device.

### `InputBuffer` [in, optional]

Supplies a pointer to an input buffer to be passed to the lower driver, or **NULL** if the request does not pass input data to lower drivers.

### `InputBufferLength` [in]

Supplies the length, in bytes, of the input buffer. If *InputBuffer* is **NULL**, *InputBufferLength* must be zero.

### `OutputBuffer` [out, optional]

Supplies a pointer to an output buffer in which the lower driver is to return data, or **NULL** if the request does not require lower drivers to return data.

### `OutputBufferLength` [in]

Supplies the length, in bytes, of the output buffer. If *OutputBuffer* is **NULL**, *OutputBufferLength* must be zero.

### `InternalDeviceIoControl` [in]

If **TRUE**, the routine sets the IRP's major function code to [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control). Otherwise, the routine sets the IRP's major function code to [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control).

### `Event` [in, optional]

Supplies a pointer to a caller-allocated and initialized event object. The I/O manager sets the event to the Signaled state when a lower-level driver completes the requested operation. After calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), the driver can wait for the event object. The *Event* parameter is optional and can be set to NULL. However, if *Event* is NULL, the caller must supply an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP to notify the caller when the operation completes.

### `IoStatusBlock` [out]

Specifies an I/O status block to be set when the request is completed by lower drivers.

## Return value

If the operation succeeds, **IoBuildDeviceIoControlRequest** returns a pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp), with the next-lower driver's I/O stack location set up from the supplied parameters. Otherwise, the routine returns **NULL**.

## Remarks

A driver can call **IoBuildDeviceIoControlRequest** to set up IRPs for device control requests that it synchronously sends to lower-level drivers.

After calling **IoBuildDeviceIoControlRequest** to create a request, the driver must call [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) to send the request to the next-lower driver. If **IoCallDriver** returns STATUS_PENDING, the driver must wait for the completion of the IRP by calling [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) on the given *Event*. Most drivers do not need to set an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP.

IRPs that are created by **IoBuildDeviceIoControlRequest** must be completed by a driver's call to [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest). A driver that calls **IoBuildDeviceIoControlRequest** must not call [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp), because the I/O manager frees these synchronous IRPs after **IoCompleteRequest** has been called.

**IoBuildDeviceIoControlRequest** queues the IRPs that it creates to an IRP queue that is specific to the current thread. If the thread exits, the I/O manager cancels the IRP.

If the caller supplies an *InputBuffer* or *OutputBuffer* parameter, this parameter must point to a buffer that resides in system memory. The caller is responsible for validating any parameter values that it copies into the input buffer from a user-mode buffer. The input buffer might contain parameter values that are interpreted differently depending on whether the originator of the request is a user-mode application or a kernel-mode driver. In the IRP that **IoBuildDeviceIoControlRequest** returns, the **RequestorMode** field is always set to **KernelMode**. This value indicates that the request, and any information contained in the request, is from a trusted, kernel-mode component.

If the caller cannot validate parameter values that it copies from a user-mode buffer to the input buffer, or if these values must not be interpreted as coming from a kernel-mode component, the caller should set the **RequestorMode** field in the IRP to **UserMode**. This setting informs the driver that handles the I/O control request that the buffer contains untrusted, user-mode data.

The actual method by which the contents of the *InputBuffer* and *OutputBuffer* parameters are stored in the IRP depends on the *TransferType* value for the IOCTL. For more information about this value, see [Buffer Descriptions for I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/buffer-descriptions-for-i-o-control-codes).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)