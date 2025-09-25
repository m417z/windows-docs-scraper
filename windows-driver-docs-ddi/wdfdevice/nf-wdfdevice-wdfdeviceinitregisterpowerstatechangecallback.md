# WdfDeviceInitRegisterPowerStateChangeCallback function

## Description

[Applies to KMDF only]

>[!NOTE]
>This method is for Microsoft internal use only.

The **WdfDeviceInitRegisterPowerStateChangeCallback** method registers a driver-supplied event callback function that the framework calls when a device's power state machine changes state.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `PowerState` [in]

A [WDF_DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_power_state) enumerator that identifies the power machine state for which the driver is requesting notification.

### `EvtDevicePowerStateChange` [in]

A caller-supplied pointer to the driver's [EvtDevicePowerStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_power_state_change_notification) event callback function.

### `CallbackTypes` [in]

An ORed combination of [WDF_STATE_NOTIFICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_state_notification_type)-typed enumerators.

## Return value

If the operation succeeds, **WdfDeviceInitRegisterPowerStateChangeCallback** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |

## Remarks

If your driver calls **WdfDeviceInitRegisterPowerStateChangeCallback**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate), see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

#### Examples

The following code example registers an event callback function that the framework will call when the device's power state machine changes state.

```cpp
status = WdfDeviceInitRegisterPowerStateChangeCallback(
                                     DeviceInit,
                                     WdfDevStatePowerD0StartingConnectInterrupt,
                                     PciDrvPowerStateChangeCallback,
                                     StateNotificationAllStates
                                     );
```