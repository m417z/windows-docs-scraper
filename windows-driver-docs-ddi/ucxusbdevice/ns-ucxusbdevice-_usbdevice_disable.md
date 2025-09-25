# _USBDEVICE_DISABLE structure

## Description

Contains parameters for a request to disable the specified device. This structure is passed by UCX in request parameters (**Parameters.Others.Arg1**) of a framework request object of the [EVT_UCX_USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_disable) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `DefaultEndpoint`

A handle to the default endpoint of the USB device or hub to disable.

### `UsbDeviceRecoveryAction`

A [**UCX_USBDEVICE_RECOVERY_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ne-ucxusbdevice-_ucx_usbdevice_recovery_action)-value that indicates FLDR or PLDR trigger resets.

## See also

[EVT_UCX_USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_disable)

[USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_enable)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)