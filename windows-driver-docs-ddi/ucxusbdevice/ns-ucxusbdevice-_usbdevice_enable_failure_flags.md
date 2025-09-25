# _USBDEVICE_ENABLE_FAILURE_FLAGS structure

## Description

The flags that are set by the client driver in the [EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable) callback function. Indicate errors, if any, that might have occurred while enabling the device.

## Members

### `InsufficientHardwareResourcesForDefaultEndpoint`

Insufficient hardware resources for transfers to the default endpoint.

### `InsufficientHardwareResourcesForDevice`

Insufficient hardware resources to enable transfers.

### `Reserved`

Do not use.

## See also

[EVT_UCX_USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_enable)

[USBDEVICE_ENABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_enable)