# WdfDeviceSetPowerCapabilities function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetPowerCapabilities** method reports a device's power capabilities.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PowerCapabilities` [in]

A pointer to a driver-allocated [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A driver typically calls **WdfDeviceSetPowerCapabilities** from within one of the following callback functions:

* [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)
* [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)
* [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) (if the *PreviousState* parameter's value is **WdfPowerDeviceD3Final**)
* [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)
* [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

If more than one driver in the device's driver stack call **WdfDeviceSetPowerCapabilities**, the power manager uses the values that are supplied by the driver that is highest in the stack.

#### Examples

The following code example initializes a WDF_DEVICE_POWER_CAPABILITIES structure and then calls **WdfDeviceSetPowerCapabilities**.

```cpp
WDF_DEVICE_POWER_CAPABILITIES powerCaps;

WDF_DEVICE_POWER_CAPABILITIES_INIT(&powerCaps);
powerCaps.DeviceD1 = WdfTrue;
powerCaps.WakeFromD1 = WdfTrue;
powerCaps.DeviceWake = PowerDeviceD1;
powerCaps.DeviceState[PowerSystemWorking] = PowerDeviceD1;
powerCaps.DeviceState[PowerSystemSleeping1] = PowerDeviceD1;
powerCaps.DeviceState[PowerSystemSleeping2] = PowerDeviceD2;
powerCaps.DeviceState[PowerSystemSleeping3] = PowerDeviceD2;
powerCaps.DeviceState[PowerSystemHibernate] = PowerDeviceD3;
powerCaps.DeviceState[PowerSystemShutdown] = PowerDeviceD3;

WdfDeviceSetPowerCapabilities(
                              device,
                              &powerCaps
                              );
```

## See also

[WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities)

[WDF_DEVICE_POWER_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_capabilities_init)

[WdfDeviceSetPnpCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpnpcapabilities)