# IoBuildSynchronousFsdRequest function

## Description

The **IoBuildSynchronousFsdRequest** routine allocates and sets up an IRP for a synchronously processed I/O request.

## Parameters

### `MajorFunction` [in]

The major function code for the IRP. This code can be [IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp), [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read), [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write), [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers), or [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown).

### `DeviceObject` [in]

A pointer to the [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure for the next-lower driver's device object, which represents the target device.

### `Buffer` [in, out]

A pointer to a data buffer. If *MajorFunction* is **IRP_MJ_WRITE**, the buffer contains data to be written. If *MajorFunction* is **IRP_MJ_READ**, the buffer receives data. If *MajorFunction* is **IRP_MJ_FLUSH_BUFFERS** or **IRP_MJ_SHUTDOWN**, this parameter must be **NULL**.

### `Length` [in, optional]

The length, in bytes, of the buffer pointed to by *Buffer*. For devices such as disks, this value must be an integer multiple of the sector size. Starting with Windows 8, the sector size can be 4,096 or 512 bytes. In earlier versions of Windows, the sector size is always 512 bytes. This parameter is required for read and write requests, but must be zero for flush and shutdown requests.

### `StartingOffset` [in, optional]

A pointer to the offset on the disk, for read and write requests. The units and meaning of this value are driver-specific. This parameter is required for read and write requests, but must be zero for flush and shutdown requests.

### `Event` [in]

A pointer to a caller-allocated and initialized event object. The I/O manager sets the event to the Signaled state when a lower-level driver completes the requested operation. After calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), the driver can wait for the event object.

### `IoStatusBlock` [out]

A pointer to a location that receives the I/O status block that is set when the IRP is completed by a lower-level driver.

## Return value

If the operation succeeds, **IoBuildSynchronousFsdRequest** returns a pointer to an initialized [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure, with the next-lower driver's I/O stack location set up from the supplied parameters. Otherwise, the routine returns **NULL**.

## Remarks

A file system driver (FSD) or other higher-level driver can call **IoBuildSynchronousFsdRequest** to set up IRPs that it synchronously sends to lower-level drivers.

**IoBuildSynchronousFsdRequest** allocates and sets up an IRP that requests lower-level drivers to perform a synchronous read, write, flush, or shutdown operation. The IRP contains enough information to start the operation.

Lower-level drivers might impose restrictions on parameters supplied to this routine. For example, disk drivers might require that values supplied for *Length* and *StartingOffset* be integer multiples of the device's sector size.

After calling **IoBuildSynchronousFsdRequest** to create a request, the driver must call [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) to send the request to the next-lower driver. If **IoCallDriver** returns STATUS_PENDING, the driver must wait for the completion of the IRP by calling [KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject) on the given *Event*. Most drivers do not need to set an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP.

IRPs that are created by **IoBuildSynchronousFsdRequest** must be completed by a driver's call to [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest). A driver that calls **IoBuildSynchronousFsdRequest** must not call [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp), because the I/O manager frees these synchronous IRPs after **IoCompleteRequest** has been called.

**IoBuildSynchronousFsdRequest** queues the IRPs that it creates to an IRP queue that is specific to the current thread. If the thread exits, the I/O manager cancels the IRP.

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[KeInitializeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)