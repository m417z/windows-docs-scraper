# IoAllocateController function

## Description

The **IoAllocateController** routine sets up the call to a driver-supplied [ControllerControl](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines) routine as soon as the device controller, represented by the given controller object, is available to carry out an I/O operation for the target device, represented by the given device object.

## Parameters

### `ControllerObject` [in]

Pointer to a driver-created controller object, usually representing a physical controller to be allocated for an I/O operation on an attached device.

### `DeviceObject` [in]

Pointer to the device object, representing the target device of the current IRP.

### `ExecutionRoutine` [in]

Pointer to the driver-supplied [ControllerControl](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines) routine.

### `Context` [in, optional]

Pointer to a driver-determined context, passed to the driver's *ControllerControl* routine when it is called.

## Remarks

This routine reserves exclusive access to the hardware controller for the specified device.

The [ControllerControl](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines) routine returns a value indicating whether the controller remains allocated to the device, either **DeallocateObject** or **KeepObject**. If it returns **KeepObject**, the driver must subsequently call **IoFreeController** to release the controller object.

## See also

[ControllerControl](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines)

[IoCreateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatecontroller)

[IoDeleteController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iodeletecontroller)

[IoFreeController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iofreecontroller)