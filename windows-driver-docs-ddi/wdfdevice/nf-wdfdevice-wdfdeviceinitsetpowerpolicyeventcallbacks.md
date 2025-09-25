# WdfDeviceInitSetPowerPolicyEventCallbacks function

## Description

[Applies to KMDF and UMDF]

The **WdfDeviceInitSetPowerPolicyEventCallbacks** method registers a driver's power policy event callback functions.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `PowerPolicyEventCallbacks` [in]

A pointer to a caller-initialized [WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks) structure.

## Remarks

If your driver calls **WdfDeviceInitSetPowerPolicyEventCallbacks**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate). For more information, see [Creating a Framework Device Object](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object).

For more information about **WdfDeviceInitSetPowerPolicyEventCallbacks**, see [Power Policy Ownership](https://learn.microsoft.com/windows-hardware/drivers/wdf/power-policy-ownership).

#### Examples

The following code example initializes a [WDF_POWER_POLICY_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_policy_event_callbacks) structure and then calls **WdfDeviceInitSetPowerPolicyEventCallbacks**.

```cpp
WDF_POWER_POLICY_EVENT_CALLBACKS powerPolicyCallbacks;

WDF_POWER_POLICY_EVENT_CALLBACKS_INIT(&powerPolicyCallbacks);
powerPolicyCallbacks.EvtDeviceArmWakeFromS0 = PciDrvEvtDeviceWakeArmS0;
powerPolicyCallbacks.EvtDeviceDisarmWakeFromS0 = PciDrvEvtDeviceWakeDisarmS0;
powerPolicyCallbacks.EvtDeviceWakeFromS0Triggered = PciDrvEvtDeviceWakeTriggeredS0;
powerPolicyCallbacks.EvtDeviceArmWakeFromSx = PciDrvEvtDeviceWakeArmSx;
powerPolicyCallbacks.EvtDeviceDisarmWakeFromSx = PciDrvEvtDeviceWakeDisarmSx;
powerPolicyCallbacks.EvtDeviceWakeFromSxTriggered = PciDrvEvtDeviceWakeTriggeredSx;
WdfDeviceInitSetPowerPolicyEventCallbacks(
                                          DeviceInit,
                                          &powerPolicyCallbacks
                                          );
```

## See also

[WDF_POWER_POLICY_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_power_policy_event_callbacks_init)

[WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks)