# _CONTROLLER_OBJECT structure

## Description

A controller object represents a hardware adapter or controller with homogenous devices that are the actual targets for I/O requests. A controller object can be used to synchronize a device driver's I/O to the target devices through its hardware adapter/controller.

A controller object is partially opaque. Driver writers must know about a certain field associated with the controller object because their drivers access this field through the controller object pointer returned by **IoCreateController**. The following field in a controller object is accessible to the creating driver.

## Members

### `Type`

### `Size`

### `ControllerExtension`

Pointer to the controller extension. The structure and contents of the controller extension are driver-defined. The size is driver-determined, specified in the driver's call to **IoCreateController**. Usually, drivers maintain common state about I/O operations in the controller extension and device-specific state about I/O for a target device in the corresponding device extension.

### `DeviceWaitQueue`

### `Spare1`

### `Spare2`

## Remarks

Most driver routines that process IRPs are given a pointer to the target device object. Consequently, device drivers that use controller objects frequently store the controller object pointer returned by **IoCreateController** in each device extension.

Note that a controller object has no name so it cannot be the target of an I/O request, and higher-level drivers cannot connect or attach their device objects to a device driver's controller object.

Undocumented fields within a controller object should be considered inaccessible. Drivers with dependencies on object field locations or access to undocumented fields might not remain portable and interoperable with other drivers over time.

## See also

[IoCreateController](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatecontroller)