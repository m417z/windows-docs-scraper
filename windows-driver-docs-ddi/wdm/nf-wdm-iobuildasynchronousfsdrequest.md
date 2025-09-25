## Description

The **IoBuildAsynchronousFsdRequest** routine allocates and sets up an IRP to be sent to lower-level drivers.

## Parameters

### `MajorFunction` [in]

The major function code to be set in the IRP. This code can be [IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp), [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read), [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write), [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers), or [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown).

### `DeviceObject` [in]

A pointer to the next-lower driver's device object. This object represents the target device for the read, write, flush, or shutdown operation.

### `Buffer` [in, out]

A pointer to a buffer into which data is read or from which data is written. The value of this argument is **NULL** for flush and shutdown requests.

### `Length` [in, optional]

The length, in bytes, of the buffer pointed to by *Buffer*. For devices such as disks, this value must be an integer multiple of the sector size. Starting with Windows 8, the sector size can be 4,096 or 512 bytes. In earlier versions of Windows, the sector size is always 512 bytes. This parameter is required for read and write requests, but must be zero for flush and shutdown requests.

### `StartingOffset` [in, optional]

A pointer to the starting offset on the input/output media. The value of this argument is zero for flush and shutdown requests.

### `IoStatusBlock` [in, optional]

A pointer to the address of an I/O status block in which the to-be-called drivers return final status about the requested operation.

## Return value

**IoBuildAsynchronousFsdRequest** returns a pointer to an IRP, or a **NULL** pointer if the IRP cannot be allocated.

## Remarks

Intermediate or highest-level drivers can call **IoBuildAsynchronousFsdRequest** to set up IRPs for requests sent to lower-level drivers. The calling driver must supply an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for the IRP, so the IRP can be deallocated with [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp). For more information about IRP deallocation, see Examples.

The IRP that gets built contains only enough information to get the operation started and to complete the IRP. No other context information is tracked because an asynchronous request is context-independent.

Lower-level drivers might impose restrictions on parameters supplied to this routine. For example, disk drivers might require that values supplied for *Length* and *StartingOffset* be integer multiples of the device's sector size.

An intermediate or highest-level driver also can call [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest), [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp), or [IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest) to set up requests it sends to lower-level drivers. Only a highest-level driver can call [IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp).

During an **IoBuildAsynchronousFsdRequest** call, the I/O manager sets the **Tail.Overlay.Thread** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure to point to the caller's thread object, but does not take a counted reference to the thread object on behalf of the caller. After the caller sends the IRP to the driver for the target device, this driver might use the **Tail.Overlay.Thread** member to access the thread object. For example, a storage driver might call the [IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice) routine and supply a pointer to the IRP as an input parameter. During this call, **IoSetHardErrorOrVerifyDevice** uses the **Tail.Overlay.Thread** member to access the thread object. When the thread object is accessed in this way, the driver that called **IoBuildAsynchronousFsdRequest** to allocate the IRP is responsible for ensuring that the thread object stays valid while the IRP is being handled.

To keep the thread object valid, the driver that calls **IoBuildAsynchronousFsdRequest** can take a counted reference on the thread object before sending the IRP. For example, this driver can call the [ObReferenceObjectByPointerWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointerwithtag) routine and supply, as the *Object* parameter, the object pointer from the **Tail.Overlay.Thread** member of the **IRP** structure. Later, this driver's completion routine can dereference the object by calling a routine such as [ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag).

A driver might call **IoBuildAsynchronousFsdRequest** in one thread, and send the IRP allocated by this call in another thread. Before sending the IRP, this driver should set the **Tail.Overlay.Thread** member of the IRP to point to the thread object for the sending thread. Typically, the driver calls the [PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread) routine to get the thread object pointer.

A driver that calls **IoBuildAsynchronousFsdRequest** to allocate an IRP does not necessarily need to take a counted reference on the thread object pointed to by the **Tail.Overlay.Thread** member of the IRP. The driver might instead use another technique to guarantee that this thread object remains valid while the IRP is being handled. For example, if the driver created the thread, the thread can wait until the IRP is completed to terminate itself.

### Examples

Before calling [IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp), an additional step is required to free the buffer for an IRP built by **IoBuildAsynchronousFsdRequest** if the following are all true:

- The buffer was allocated from system memory pool.

- In the device object for the target device, the DO_DIRECT_IO flag is set in the **DeviceObject->Flags** field.

- The **Irp->MdlAddress** field is non-NULL.

Before freeing the buffer for this IRP, call the [MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages) routine with **Irp->MdlAddress** as the parameter value. This call decrements the extra reference count that **IoBuildAsynchronousFsdRequest** added to the pool pages in the MDL. Otherwise, the subsequent call to [IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl) will bug check because the reference count for these pool pages will be 2, not 1. The following code example shows the **MmUnlockPages**, **IoFreeMdl**, and **IoFreeIrp** calls for this case:

```cpp
if (((DeviceObject->Flags & DO_DIRECT_IO) == DO_DIRECT_IO) &&
    (Irp->MdlAddress != NULL))
{
    MmUnlockPages(Irp->MdlAddress);
}

IoFreeMdl(Irp->MdlAddress);
IoFreeIrp(Irp);
```

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl)

[IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)

[IoSetHardErrorOrVerifyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iosetharderrororverifydevice)

[MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages)

[ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag)

[ObReferenceObjectByPointerWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointerwithtag)

[PsGetCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)