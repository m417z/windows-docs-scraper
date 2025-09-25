# IoAllocateIrp function

## Description

The **IoAllocateIrp** routine allocates an IRP, given the number of I/O stack locations for each driver layered under the caller, and, optionally, for the caller. See also [**IoAllocateIrpEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirpex).

## Parameters

### `StackSize` [in]

Specifies the number of I/O stack locations to be allocated for the IRP. This value must be at least equal to the **StackSize** of the next-lower driver's device object, but can be one greater than this value. The calling driver need not allocate a stack location in the IRP for itself.

### `ChargeQuota` [in]

Setting this to **TRUE** causes the memory allocated for the IRP to be charged against the quota for the current process. Should be set to **FALSE** by intermediate drivers. This can be set to **TRUE** only by highest-level drivers that are called in the context of the thread that originates the I/O request for which the driver is allocating another IRP.

## Return value

**IoAllocateIrp** returns a pointer to an IRP, which was allocated from nonpaged system space, or **NULL** if an IRP could not be allocated.

## Remarks

The **IoAllocateIrp** routine does not associate the IRP with a thread. The allocating driver must free the IRP instead of completing it back to the I/O manager.

An intermediate or highest-level driver can call **IoAllocateIrp** to create IRPs for requests it sends to lower-level drivers. Such a driver must initialize the IRP and must set its [**IoCompletion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine in the IRP it creates so the caller can dispose of the IRP when lower-level drivers have completed processing of the request.

**IoAllocateIrp** automatically initializes the IRP's members. Do not use **IoInitializeIrp** to initialize the IRP before its first use. (You can use **IoInitializeIrp** to reuse an IRP that you have already used under certain special circumstances. See [Reusing IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/reusing-irps) for details.)

An intermediate or highest-level driver also can call [**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest), [**IoBuildAsynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest) or [**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest) to set up requests it sends to lower-level drivers. Only a highest-level driver can call [**IoMakeAssociatedIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp).

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[**IoAllocateIrpEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirpex)

[**IoBuildAsynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest)

[**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest)

[**IoBuildSynchronousFsdRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest)

[**IoFreeIrp**](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[**IoMakeAssociatedIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)

[**IoReuseIrp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreuseirp)

[**IoSetCompletionRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)