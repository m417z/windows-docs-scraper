# _WWAN_SERVICE_ACTIVATION_STATUS structure

## Description

The WWAN_SERVICE_ACTIVATION_STATUS structure represents the status of service activation on the MB
device.

## Members

### `uNwError`

A network-specific error, if any, that is returned by the network provider. Miniport drivers
should populate this member only if
**uStatus** does not equal WWAN_STATUS_SUCCESS.

### `uVendorSpecificBufferSize`

The size, in bytes, of the vendor-specific buffer that follows the structure instance in
memory.

## See also

[NDIS_WWAN_SERVICE_ACTIVATION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_service_activation_status)