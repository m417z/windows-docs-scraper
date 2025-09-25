# _USBDEVICE_UPDATE_FAILURE_FLAGS structure

## Description

The flags that are set by the client driver in the [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) callback function. Indicate errors, if any, that might have occurred while updating the device.

## Members

### `MaxExitLatencyTooLarge`

The maximum exit latency is larger than expected.

### `Reserved`

Do not use.

## See also

[USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update)

[USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_20_hardware_lpm_parameters)

[USBDEVICE_UPDATE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_flags)