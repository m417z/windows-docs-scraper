# EVT_UFX_DEVICE_CONTROLLER_RESET callback function

## Description

The client driver's implementation to reset the function controller to its initial state.

## Parameters

### `unnamedParam1` [in]

The handle to a USB device object that the client driver received in a previous call to the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `unnamedParam2` [in, optional]

A pointer to a variable-length UFX_HARDWARE_FAILURE_CONTEXT structure allocated by the client driver.

## Remarks

The client driver for the function host controller registers its *EVT_UFX_DEVICE_CONTROLLER_RESET* implementation with the USB function class extension (UFX) by calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) method.

The client driver indicates completion of this event by calling the [UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete) method.

## See also

[UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate)

[UfxDeviceEventComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdeviceeventcomplete)