# WdfDeviceInitRegisterPnpStateChangeCallback function

## Description

[Applies to KMDF only]

>[!NOTE]
>This method is for Microsoft internal use only.

The **WdfDeviceInitRegisterPnpStateChangeCallback** method registers a driver-supplied event callback function that the framework calls when a device's Plug and Play state machine changes state.

## Parameters

### `DeviceInit` [in]

A caller-supplied pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

### `PnpState` [in]

A [WDF_DEVICE_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_pnp_state) enumerator that identifies the Plug and Play machine state for which the driver is requesting notification.

### `EvtDevicePnpStateChange` [in]

A caller-supplied pointer to the driver's [EvtDevicePnpStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_pnp_state_change_notification) event callback function.

### `CallbackTypes` [in]

An ORed combination of [WDF_STATE_NOTIFICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_state_notification_type)-typed enumerators.

## Return value

If the operation succeeds, **WdfDeviceInitRegisterPnpStateChangeCallback** returns STATUS_SUCCESS. Additional return values include:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is insufficient memory to complete the operation. |

## Remarks

If your driver calls **WdfDeviceInitRegisterPnpStateChangeCallback**, it must do so before it calls [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

For more information about **WdfDeviceInitRegisterPnpStateChangeCallback**, see [State Machines in the Framework](https://learn.microsoft.com/windows-hardware/drivers/wdf/state-machines-in-the-framework).

#### Examples

The following code example registers an event callback function that the framework will call when the device's Plug and Play state machine changes state.

```cpp
status = WdfDeviceInitRegisterPnpStateChangeCallback(
                                                     DeviceInit,
                                                     WdfDevStatePnpEjectFailed,
                                                     MyDrvPnPStateChangeCallback,
                                                     StateNotificationAllStates
                                                     );
```

## See also

[EvtDevicePnpStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_pnp_state_change_notification)

[WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init)

[WDF_DEVICE_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_pnp_state)

[WDF_STATE_NOTIFICATION_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_state_notification_type)