# UcxUsbDeviceInitSetEventCallbacks function

## Description

Initializes a **UCXUSBDEVICE_INIT** structure with client driver's event callback functions.

## Parameters

### `UsbDeviceInit` [in, out]

A pointer to a **UCXUSBDEVICE_INIT** structure that UCX passes when it invokes client driver's [EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add) event callback function.

### `EventCallbacks` [in]

A pointer to a [UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks) structure that contains function pointer to client driver's event callback functions. The client driver initializes the structure by calling [UCX_USBDEVICE_EVENT_CALLBACKS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucx_usbdevice_event_callbacks_init).

## Remarks

An initialized **UCXUSBDEVICE_INIT** structure is used by the [UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate) method to create a USB device and register the client driver's event callback functions.

For a code example, see [EVT_UCX_CONTROLLER_USBDEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxcontroller/nc-ucxcontroller-evt_ucx_controller_usbdevice_add).

## See also

[UCX_USBDEVICE_EVENT_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_ucx_usbdevice_event_callbacks)

[UcxUsbDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nf-ucxusbdevice-ucxusbdevicecreate)