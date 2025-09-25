# _WWAN_DEVICE_SERVICE_SESSION_WRITE structure

## Description

The WWAN_DEVICE_SERVICE_SESSION_WRITE structure represents data associated with a device service session write request.

## Members

### `uSessionID`

The session ID of the device service.

### `uDataSize`

The size, in bytes, of the device service data that follows the structure instance in memory. This value should not exceed the value of the **uMaxSessionDataSize** member of the [WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services) structure.

## See also

[NDIS_WWAN_DEVICE_SERVICE_SESSION_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_service_session_write)

[WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services)