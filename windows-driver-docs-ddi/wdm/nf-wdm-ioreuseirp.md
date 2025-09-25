# IoReuseIrp function

## Description

The **IoReuseIrp** routine reinitializes an IRP so that it can be reused.

## Parameters

### `Irp` [in, out]

Pointer to the IRP to be reinitialized for reuse.

### `Iostatus` [in]

Specifies the NTSTATUS value to be set in the IRP after it is reinitialized.

## Remarks

Drivers for Windows 2000 and later versions of Windows use **IoReuseIrp** to reuse an IRP.

A driver should use **IoReuseIrp** only on IRPs it previously allocated either as raw memory or with [IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp). In particular, drivers should not use this routine for IRPs created with [IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp), [IoBuildSynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildsynchronousfsdrequest), [IoBuildAsynchronousFsdRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildasynchronousfsdrequest), or [IoBuildDeviceIoControlRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest).

See [Reusing IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/reusing-irps) for more details on how to reuse IRPs.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoInitializeIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioinitializeirp)

[IoMakeAssociatedIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iomakeassociatedirp)