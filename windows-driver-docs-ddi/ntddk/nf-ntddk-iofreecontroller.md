# IoFreeController function

## Description

The **IoFreeController** routine releases a previously allocated controller object when the driver has completed an I/O request.

## Parameters

### `ControllerObject` [in]

Pointer to the driver's controller object, which was allocated for the current I/O operation on a particular device by calling **IoAllocateController**.

## Remarks

The connection between the current target device object and the controller object is released only if no requests are currently queued to the same device. Otherwise, the driver's ControllerControl routine is called with the next IRP bound through the device controller to the target device.

## See also

[IoAllocateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-ioallocatecontroller)

[IoCreateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatecontroller)

[IoDeleteController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeletecontroller)