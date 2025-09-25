# _USBDEVICE_ENABLE structure

## Description

Contains parameters for a request to enable the specified device. This structure is passed by UCX in request parameters (**Parameters.Others.Arg1**) of a framework request object of the [EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that contains the handle for the USB hub or device.

### `DefaultEndpoint`

The default endpoint for the USB hub or device to enable transfers for.

### `FailureFlags`

The errors, if any, that occurred when attempting to enable the hub or device for transfers.

## See also

[USBDEVICE_DISABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_disable)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)