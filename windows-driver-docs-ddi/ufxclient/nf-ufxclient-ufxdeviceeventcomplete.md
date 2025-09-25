# UfxDeviceEventComplete function

## Description

Informs UFX that the client driver has completed processing a UFX callback function.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `Status` [in]

Status of the event being completed.

## Remarks

The client driver calls **UfxDeviceEventComplete** to signal completion of the following callback functions:

* [EVT_UFX_DEVICE_HOST_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_host_connect)
* [EVT_UFX_DEVICE_HOST_DISCONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_host_disconnect)
* [EVT_UFX_DEVICE_PROPRIETARY_CHARGER_SET_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_set_property)
* [EVT_UFX_DEVICE_PROPRIETARY_CHARGER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_proprietary_charger_reset)
* [EVT_UFX_DEVICE_ADDRESSED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_addressed)
* [EVT_UFX_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_default_endpoint_add)
* [EVT_UFX_DEVICE_USB_STATE_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_usb_state_change)
* [EVT_UFX_DEVICE_PORT_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_port_change)
* [EVT_UFX_DEVICE_REMOTE_WAKEUP_SIGNAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_remote_wakeup_signal)
* [EVT_UFX_DEVICE_TEST_MODE_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_test_mode_set)
* [EVT_UFX_DEVICE_SUPER_SPEED_POWER_FEATURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_super_speed_power_feature)
* [EVT_UFX_DEVICE_CONTROLLER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_controller_reset)

For example, your callback function could use the following code:

```
    EventComplete = TRUE;

    ...

    if (EventComplete) {
        UfxDeviceEventComplete(UfxDevice, STATUS_SUCCESS);
    }

```