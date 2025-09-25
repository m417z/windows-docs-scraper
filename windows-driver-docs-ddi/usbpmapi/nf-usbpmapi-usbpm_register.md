# UsbPm_Register function

## Description

Registers the client driver with the Policy Manager to report hub arrival/removal and connector state changes.

## Parameters

### `ClientConfig` [In]

The pointer to a caller-supplied [**USBPM_CLIENT_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/ns-usbpmapi-_usbpm_client_config) structure. Initialize the structure by calling macro [**USBPM_CLIENT_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_client_config_init).

### `ClientHandle` [Out]

A pointer to a location that receives a handle to the registration operation.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

The client driver's callback functions might start getting invoked before **UsbPm_Register** returns. The _ClientHandle_ value is set to a valid value before callback functions are invoked.

The driver typically calls **UsbPm_Register** in the driver's [**EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init) and unregisters in [**EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup) by calling [**UsbPm_Deregister**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_deregister).

## See also