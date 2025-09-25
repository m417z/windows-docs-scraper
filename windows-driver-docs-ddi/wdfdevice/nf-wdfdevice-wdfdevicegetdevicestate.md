# WdfDeviceGetDeviceState function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceGetDeviceState** method retrieves the device state for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceState` [in, out]

A pointer to a caller-allocated [WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state) structure that receives the device's state information.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WDF_DEVICE_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_state_init)