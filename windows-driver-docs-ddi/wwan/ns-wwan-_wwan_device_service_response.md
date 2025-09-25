# _WWAN_DEVICE_SERVICE_RESPONSE structure

## Description

The WWAN_DEVICE_SERVICE_RESPONSE structure represents a response from a device service.

## Members

### `DeviceServiceGuid`

The GUID of the device service that the response originated from.

### `ResponseID`

The ID of the response.

### `uDataSize`

The size, in bytes, of the device service response data that follows the structure instance in memory. This value should not exceed the value of the **uMaxCommandDataSize** member of the [WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services) structure.

## See also

[WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services)