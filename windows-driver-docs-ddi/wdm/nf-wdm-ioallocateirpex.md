# IoAllocateIrpEx function

## Description

**IoAllocateIrpEx** allocates an IRP from the system nonpaged pool, possibly with an IRP extension.

## Parameters

### `DeviceObject`

Pointer to the device object to check to determine whether to add space for an IRP extension. When **DeviceObject** is set to DEVICE_WITH_IRP_EXTENSION, space for the IRP extension is also allocated.

### `StackSize`

Maximum number of stack locations to be allocated for the IRP. **StackSize** must be at least equal to the **StackSize** of the next-lower driver's device object, but can be one greater than this value. The calling driver does not need to allocate a stack location in the IRP for itself.

### `ChargeQuota`

Setting **ChargeQuota** to **TRUE** causes the memory allocated for the IRP to be charged against the quota for the current process. This parameter can be set **TRUE** only by the highest-level drivers that are called in the context of the thread that originates the I/O request for which the driver is allocating another IRP. Intermediate drivers should set this parameter to **FALSE**.

## Return value

**IoAllocateIrpEx** returns a pointer to the allocated and initialized IRP, or **NULL** if an IRP could not be allocated.

## Remarks

**IoAllocateIrpEx** allocates **StackSize** stack locations and initializes the IRP. It does not associate the IRP with a thread. The allocating driver must free the IRP instead of completing it back to the I/O manager.

An intermediate or highest-level driver can call **IoAllocateIrpEx** to create IRPs for requests it sends to lower-level drivers. Such a driver must initialize the IRP and must set its [*IoCompletion*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) callback routine in the IRP it creates so the caller can dispose of the IRP when lower-level drivers have completed processing of the request.
IoAllocateIrp automatically initializes the IRP's members. Do not use IoInitializeIrp to initialize the IRP before its first use. (You can use IoInitializeIrp to reuse an IRP that you have already used under certain special circumstances. See [Reusing IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/reusing-irps) for details.)
An intermediate or highest-level driver also can call [**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest), [**IoBuildAsynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest) or [**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest) to set up requests it sends to lower-level drivers. Only a highest-level driver can call [**IoMakeAssociatedIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[**IoAllocateIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[**IoBuildAsynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[*IoCompletion*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine)

[**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[**IoFreeIrp**](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[**IoMakeAssociatedIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)

[**IoReuseIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreuseirp)

[**IoSetCompletionRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)