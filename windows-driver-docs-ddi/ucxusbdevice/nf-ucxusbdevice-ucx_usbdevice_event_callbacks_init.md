# UCX_USBDEVICE_EVENT_CALLBACKS_INIT function

## Description

Initializes a [UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks) structure with the function pointers to client driver's callback functions.

## Parameters

### `Callbacks` [out]

 A pointer to a [UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks) structure to initialize.

### `EvtUsbDeviceEndpointsConfigure` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoints_configure) event callback function.

### `EvtUsbDeviceEnable` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable) event callback function.

### `EvtUsbDeviceDisable` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_disable) event callback function.

### `EvtUsbDeviceReset` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_reset) event callback function.

### `EvtUsbDeviceAddress` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_address) event callback function.

### `EvtUsbDeviceUpdate` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) event callback function.

### `EvtUsbDeviceHubInfo` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_HUB_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_hub_info) event callback function.

### `EvtUsbDeviceDefaultEndpointAdd` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_default_endpoint_add) event callback function.

### `EvtUsbDeviceEndpointAdd` [in]

 A pointer to client driver's implementation of the [EVT_UCX_USBDEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoint_add) event callback function.

## See also

[UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)

[UcxUsbDeviceInitSetEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdeviceinitseteventcallbacks)