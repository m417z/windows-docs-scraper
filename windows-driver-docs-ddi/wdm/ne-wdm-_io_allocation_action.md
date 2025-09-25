# _IO_ALLOCATION_ACTION enumeration

## Description

The **IO_ALLOCATION_ACTION** enumerated type is used to specify return values for [AdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_control) and [ControllerControl](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-controllercontrolroutines) routines.

## Constants

### `KeepObject`

Indicates that you want the driver to retain ownership of the adapter or controller object.

### `DeallocateObject`

Indicates that you do not want the driver to retain ownership of the adapter or controller object.

### `DeallocateObjectKeepRegisters`

For adapter objects only. Indicates that you do not want the driver to retain ownership of the adapter object, but you do want the driver to retain ownership of the allocated map registers.

## Remarks

If an *AdapterControl* or *ControllerControl* routine completes an IRP, or if it can set up an operation (such as a disk seek) for a target device object that could be overlapped with an operation for another device object, it should return **DeallocateObject**.

If a driver uses packet-based bus-master DMA, its *AdapterControl* routine should return **DeallocateObjectKeepRegisters**.

Otherwise, the driver should return **KeepObject**.