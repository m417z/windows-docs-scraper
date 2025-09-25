## Description

The **EVT_HIDSPICX_RESETDEVICE** callback function is implemented by the client driver to respond to requests to reset the device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

## Return value

[**NTSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) value indicating whether the reset was successful or not.

## Remarks

The class extension will call this function only while the hardware is in a working state, at passive IRQL.

The client driver synchronously resets the device and returns a status code indicating whether the reset was successful.

## See also