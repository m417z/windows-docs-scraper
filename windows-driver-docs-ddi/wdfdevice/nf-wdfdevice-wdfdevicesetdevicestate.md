# WdfDeviceSetDeviceState function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetDeviceState** method sets the device state for a specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceState` [in]

A pointer to a driver-allocated [WDF_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_state) structure that contains the device's state information.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

When a driver calls **WdfDeviceSetDeviceState**, the framework notifies the Plug and Play (PnP) manager that the device state has changed.

#### Examples

The following code example informs the PnP manager that a specified device is disabled.

```cpp
WDF_DEVICE_STATE    deviceState;

WDF_DEVICE_STATE_INIT (&deviceState);
deviceState.Disabled = WdfTrue;
WdfDeviceSetDeviceState (
                         Device,
                         &deviceState
                         );
```

## See also

[WDF_DEVICE_STATE_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_state_init)