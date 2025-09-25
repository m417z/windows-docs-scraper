# _USBDEVICE_UPDATE_20_HARDWARE_LPM_PARAMETERS structure

## Description

Contains parameters for a request to update USB 2.0 link power management (LPM). UCX passes this structure in the [EVT_UCX_USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_update) callback function.

## Members

### `HardwareLpmEnable`

If set, indicates are request to enable hardware LPM.

### `RemoteWakeEnable`

If set, indicates are request to enable remote wake signal.

### `HostInitiatedResumeDurationMode`

The requested resume period.

### `BestEffortServiceLatency`

The requested best effort service latency.

### `BestEffortServiceLatencyDeep`

The requested best effort service latency deep.

### `L1Timeout`

The requested L1 timeout.

### `Reserved`

Do not use.

## See also

[ROOTHUB_20PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_20port_info)

[USBDEVICE_UPDATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update)

[USBDEVICE_UPDATE_FAILURE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_failure_flags)

[USBDEVICE_UPDATE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_update_flags)