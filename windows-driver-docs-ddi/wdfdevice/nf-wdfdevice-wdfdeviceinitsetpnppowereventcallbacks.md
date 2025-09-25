# WdfDeviceInitSetPnpPowerEventCallbacks function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetPnpPowerEventCallbacks** method registers a driver's Plug and Play and power management event callback functions.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `PnpPowerEventCallbacks` [in]

A pointer to a caller-initialized [WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks) structure.

## Remarks

If your driver calls **WdfDeviceInitSetPnpPowerEventCallbacks**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

#### Examples

The following code example initializes a [WDF_PNPPOWER_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_pnppower_event_callbacks) structure and then calls **WdfDeviceInitSetPnpPowerEventCallbacks**.

```cpp
WDF_PNPPOWER_EVENT_CALLBACKS  pnpPowerCallbacks;

WDF_PNPPOWER_EVENT_CALLBACKS_INIT(&pnpPowerCallbacks);
pnpPowerCallbacks.EvtDevicePrepareHardware = SerialEvtPrepareHardware;
pnpPowerCallbacks.EvtDeviceReleaseHardware = SerialEvtReleaseHardware;
pnpPowerCallbacks.EvtDeviceD0Entry = SerialEvtDeviceD0Entry;
pnpPowerCallbacks.EvtDeviceD0Exit = SerialEvtDeviceD0Exit;
WdfDeviceInitSetPnpPowerEventCallbacks(
                                       DeviceInit,
                                       &pnpPowerCallbacks
                                       );
```

## See also

[WDF_PNPPOWER_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_pnppower_event_callbacks_init)

[WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks)