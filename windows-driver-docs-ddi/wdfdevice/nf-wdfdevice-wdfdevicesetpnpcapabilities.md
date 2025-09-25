# WdfDeviceSetPnpCapabilities function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceSetPnpCapabilities** method reports a device's Plug and Play capabilities.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `PnpCapabilities` [in]

A pointer to a driver-allocated [WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities) structure.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A driver typically calls **WdfDeviceSetPnpCapabilities** from within one of the following callback functions:

* [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)
* [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware)
* [EvtDeviceD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry) (if the *PreviousState* parameter's value is **WdfPowerDeviceD3Final**)
* [EvtDeviceSelfManagedIoInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)
* [EvtChildListCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device)

If more than one driver in the device's driver stack call **WdfDeviceSetPnpCapabilities**, the Plug and Play manager uses the values that are supplied by the driver that is highest in the stack.

#### Examples

The following code examples initializes a WDF_DEVICE_PNP_CAPABILITIES structure and then calls **WdfDeviceSetPnpCapabilities**.

```cpp
WDF_DEVICE_PNP_CAPABILITIES  pnpCaps;

WDF_DEVICE_PNP_CAPABILITIES_INIT(&pnpCaps);
pnpCaps.SurpriseRemovalOK = WdfTrue;

WdfDeviceSetPnpCapabilities(
                            device,
                            &pnpCaps
                            );
```

## See also

[WDF_DEVICE_PNP_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_pnp_capabilities)

[WDF_DEVICE_PNP_CAPABILITIES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_pnp_capabilities_init)

[WdfDeviceSetPowerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetpowercapabilities)