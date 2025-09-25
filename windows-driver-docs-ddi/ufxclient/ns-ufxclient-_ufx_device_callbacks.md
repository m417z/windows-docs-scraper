# _UFX_DEVICE_CALLBACKS structure

## Description

The **UFX_DEVICE_CALLBACKS** structure is used to define then event callback functions supported by the client driver.

## Members

### `Size`

The size of the **UFX_DEVICE_CALLBACKS** structure.

### `EvtDeviceHostConnect`

A pointer to the client driver’s [EVT_UFX_DEVICE_HOST_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_host_connect) callback routine.

### `EvtDeviceHostDisconnect`

A pointer to the client driver’s [EVT_UFX_DEVICE_HOST_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_host_disconnect) callback routine.

### `EvtDeviceAddressed`

A pointer to the client driver’s [EVT_UFX_DEVICE_ADDRESSED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_addressed) callback routine.

### `EvtDeviceEndpointAdd`

A pointer to the client driver’s [EVT_UFX_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_endpoint_add) callback routine.

### `EvtDeviceDefaultEndpointAdd`

A pointer to the client driver’s [EVT_UFX_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_default_endpoint_add) callback routine.

### `EvtDeviceUsbStateChange`

A pointer to the client driver’s [EVT_UFX_DEVICE_USB_STATE_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_usb_state_change) callback routine.

### `EvtDevicePortChange`

A pointer to the client driver’s [EVT_UFX_DEVICE_PORT_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_port_change) callback routine.

### `EvtDevicePortDetect`

A pointer to the client driver’s [EVT_UFX_DEVICE_PORT_DETECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_port_detect) callback routine.

### `EvtDeviceRemoteWakeupSignal`

A pointer to the client driver’s [EVT_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_remote_wakeup_signal) callback routine.

### `EvtDeviceControllerReset`

A pointer to the client driver’s [EVT_UFX_DEVICE_CONTROLLER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_controller_reset) callback routine.

### `EvtDeviceTestModeSet`

A pointer to the client driver’s [EVT_UFX_DEVICE_TEST_MODE_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_test_mode_set) callback routine.

### `EvtDeviceTestHook`

Reserved. Should be set to NULL.

### `EvtDeviceSuperSpeedPowerFeature`

A pointer to the client driver’s [EVT_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_super_speed_power_feature) callback routine.

### `EvtDeviceProprietaryChargerDetect`

A pointer to the client driver’s [EVT_UFX_DEVICE_DETECT_PROPRIETARY_CHARGER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_detect) callback routine.

### `EvtDeviceProprietaryChargerSetProperty`

A pointer to the client driver’s [EVT_UFX_DEVICE_PROPRIETARY_CHARGER_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_set_property) callback routine.

### `EvtDeviceProprietaryChargerReset`

A pointer to the client driver’s [EVT_UFX_DEVICE_PROPRIETARY_CHARGER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_reset) callback routine.

## Remarks

The client driver shall use the [UFX_DEVICE_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufx_device_callbacks_init) macro to initialize the **UFX_DEVICE_CALLBACKS** structure, and then shall set fields of structure to the appropriate event callback routines prior to calling the [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate) export function.