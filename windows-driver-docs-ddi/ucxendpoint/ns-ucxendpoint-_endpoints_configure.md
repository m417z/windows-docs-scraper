# _ENDPOINTS_CONFIGURE structure

## Description

Describes endpoints to enable or disable endpoints. This structure is passed by UCX in the [EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoints_configure) callback function.

## Members

### `Header`

A [USBDEVICE_MGMT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/ns-ucxusbdevice-_usbdevice_mgmt_header) structure that stores handles to the USB hub or device whose endpoints.

### `EndpointsToEnableCount`

The number of endpoints to configure.

### `EndpointsToEnable`

A pointer to the first endpoint handle in the array of endpoints to enable.

### `EndpointsToDisableCount`

The number of endpoints to configure.

### `EndpointsToDisable`

A pointer to the first endpoint handle in the array of endpoints to enable.

### `EndpointsEnabledAndUnchangedCount`

The number of endpoints that were enabled and unchanged.

### `EndpointsEnabledAndUnchanged`

A pointer to the first endpoint handle in the array of endpoints that have not been changed.

### `FailureFlags`

The errors, if any, that might occur when attempting to configure endpoints for the USB device or hub.

### `ExitLatencyDelta`

The Exit Latency Delta (ELD) value. For more information see section 4.6.6.1 of the eXtensible Host Controller Interface specification.

### `ConfigurationValue`

The configuration number of the USB configuration that contains the endpoints.

### `InterfaceNumber`

The interface number of the USB interface that contains the endpoints.

### `AlternateSetting`

The setting number of the alternate setting that contains the endpoints.

### `Reserved1`

### `Reserved2`

## See also

[EVT_UCX_USBDEVICE_ENDPOINTS_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxusbdevice/nc-ucxusbdevice-evt_ucx_usbdevice_endpoints_configure)