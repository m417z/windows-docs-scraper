# _UDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS structure

## Description

Initializes a **UDECX_USB_DEVICE_STATE_CHANGE_CALLBACKS** structure with pointers to callback functions that are implemented by a UDE client for a virtual USB device.

## Members

### `Size`

The size of this structure.

### `EvtUsbDeviceLinkPowerEntry`

A pointer to an [EVT_UDECX_USB_DEVICE_D0_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_entry) callback function implemented by a UDE client driver.

### `EvtUsbDeviceLinkPowerExit`

A pointer to an [EVT_UDECX_USB_DEVICE_D0_EXIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_d0_exit) callback function implemented by a UDE client driver.

### `EvtUsbDeviceSetFunctionSuspendAndWake`

### `EvtUsbDeviceReset`

### `EvtUsbDeviceDefaultEndpointAdd`

A pointer to an [EVT_UDECX_USB_DEVICE_DEFAULT_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_default_endpoint_add) callback function implemented by a UDE client driver.

### `EvtUsbDeviceEndpointAdd`

A pointer to an E[VT_UDECX_USB_DEVICE_ENDPOINT_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoint_add) callback function implemented by a UDE client driver.

### `EvtUsbDeviceEndpointsConfigure`

A pointer to an [EVT_UDECX_USB_DEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nc-udecxusbdevice-evt_udecx_usb_device_endpoints_configure) callback function implemented by a UDE client driver.

## See also

[UdecxUsbDeviceInitSetStateChangeCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/udecxusbdevice/nf-udecxusbdevice-udecxusbdeviceinitsetstatechangecallbacks)