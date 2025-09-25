# WdfControlFinishInitializing function

## Description

[Applies to KMDF only]

The **WdfControlFinishInitializing** method informs the framework that a driver has finished initializing a specified control device object.

## Parameters

### `Device` [in]

A handle to a control device object.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

The system will not send I/O requests or Windows Management Instrumentation (WMI) requests to a control device object unless the driver has called **WdfControlFinishInitializing**.

For more information about control device objects and calling **WdfControlFinishInitializing**, see [Using Control Device Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-control-device-objects).

#### Examples

For a code example that uses **WdfControlFinishInitializing**, see [WdfControlDeviceInitAllocate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate).