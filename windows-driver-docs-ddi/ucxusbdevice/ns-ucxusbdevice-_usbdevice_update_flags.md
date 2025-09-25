# _USBDEVICE_UPDATE_FLAGS structure

## Description

Contains request flags set by UCX that is passed in the [USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update) structure when UCX invokes the client driver's [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) callback function.

## Members

### `UpdateDeviceDescriptor`

If set, indicates a request to update the USB device descriptor.

### `UpdateBosDescriptor`

If set, indicates a request to update the USB BOS descriptor.

### `UpdateMaxExitLatency`

If set, indicates a request to update the maximum exit latency.

### `UpdateIsHub`

If set, indicates a request to determine of the device is a hub.

### `UpdateAllowIoOnInvalidPipeHandles`

If set, indicates the USB device or hub has been updated to allow I/O with invalid pipe handles.

### `Update20HardwareLpmParameters`

If set, indicates a request to update the 2.0 LPM state.

### `UpdateRootPortResumeTime`

If set, indicates a request to update the root port resume time.

### `UpdateTunnelState`

If set, indicates a request to update the USB tunnel state.

### `Reserved`

Do not use.

## See also

- [USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update)
- [USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_20_hardware_lpm_parameters)
- [USBDEVICE_UPDATE_FAILURE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_failure_flags)