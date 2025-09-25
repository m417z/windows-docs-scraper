# IoInitializeIrp function

## Description

The **IoInitializeIrp** routine initializes a given IRP that was allocated by the caller.

## Parameters

### `Irp` [in, out]

Pointer to the IRP to be initialized.

### `PacketSize` [in]

Specifies the size in bytes of the IRP.

### `StackSize` [in]

Specifies the number of stack locations in the IRP.

## Remarks

Drivers use **IoInitializeIrp** to initialize IRPs the driver allocated as raw memory. Do not use **IoInitializeIrp** to initialize an IRP allocated by **IoAllocateIrp**. **IoAllocateIrp** automatically initializes the members of the IRP.

Drivers can use **IoInitializeIrp** to reinitialize an IRP for reuse only under certain circumstances. See [Reusing IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/reusing-irps) for details.

If the driver associates an MDL with the IRP it allocated, the driver is responsible for releasing the MDL when the IRP is completed.

An intermediate or highest-level driver also can call **IoBuildDeviceIoControlRequest**, **IoBuildAsynchronousFsdRequest**, or **IoBuildSynchronousFsdRequest** to set up requests it sends to lower-level drivers. Only a highest-level driver can call **IoMakeAssociatedIrp**.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoAllocateIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocateirp)

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[IoFreeIrp](https://learn.microsoft.com/windows-hardware/drivers/devtest/storport-iofreeirp)

[IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl)

[IoReuseIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreuseirp)

[IoSetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetnextirpstacklocation)

[IoSizeOfIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iosizeofirp)