# WdfDeviceGetDriver function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceGetDriver** method returns a handle to the framework driver object that is associated with a specified framework device object.

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

**WdfDeviceGetDriver** returns a handle to a framework driver object.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfDriverGetRegistryPath](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivergetregistrypath)