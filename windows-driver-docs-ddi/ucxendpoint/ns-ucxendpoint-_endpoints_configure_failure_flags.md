# _ENDPOINTS_CONFIGURE_FAILURE_FLAGS structure

## Description

This structure provides failure flags to indicate errors, if any, that might have occurred during a request to an [EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoints_configure) callback function.

## Members

### `InsufficientBandwidth`

Insufficient bandwidth to configure the specified endpoints.

### `InsufficientHardwareResourcesForEndpoints`

Insufficient hardware resources to configure the specified endpoints.

### `MaxExitLatencyTooLarge`

The maximum exit latency is too large to configure the specified endpoints.

### `Reserved`

Do not use.

## See also

[ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxendpoint/ns-ucxendpoint-_endpoints_configure)