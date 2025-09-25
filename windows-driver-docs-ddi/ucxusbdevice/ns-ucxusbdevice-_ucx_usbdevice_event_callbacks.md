# _UCX_USBDEVICE_EVENT_CALLBACKS structure

## Description

This structure provides a list of UCX USB device event callback functions.

## Members

### `Size`

The size in bytes of this structure.

### `EvtUsbDeviceEndpointsConfigure`

A pointer to an [EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoints_configure) callback function.

### `EvtUsbDeviceEnable`

A pointer to an [EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable) callback function.

### `EvtUsbDeviceDisable`

A pointer to an [EVT_UCX_USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_disable) callback function.

### `EvtUsbDeviceReset`

A pointer to an [EVT_UCX_USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_reset) callback function.

### `EvtUsbDeviceAddress`

A pointer to an [EVT_UCX_USBDEVICE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_address) callback function.

### `EvtUsbDeviceUpdate`

A pointer to an [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) callback function.

### `EvtUsbDeviceHubInfo`

A pointer to an [EVT_UCX_USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_hub_info) callback function.

### `EvtUsbDeviceDefaultEndpointAdd`

A pointer to an [EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_default_endpoint_add) callback function.

### `EvtUsbDeviceEndpointAdd`

A pointer to an [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add) callback function.

### `EvtUsbDeviceSuspend`

A pointer to an [EVT_UCX_USBDEVICE_SUSPEND](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_suspend) callback function.

### `EvtUsbDeviceResume`

A pointer to an [EVT_UCX_USBDEVICE_RESUME](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_resume) callback function.

### `EvtUsbDeviceGetCharacteristic`

A pointer to an [EVT_UCX_USBDEVICE_GET_CHARACTERISTIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_get_characteristic) callback function.

## See also

[UCX_USBDEVICE_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucx_usbdevice_event_callbacks_init)

[UcxUsbDeviceInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdeviceinitseteventcallbacks)