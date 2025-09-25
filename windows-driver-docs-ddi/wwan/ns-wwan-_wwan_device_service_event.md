# _WWAN_DEVICE_SERVICE_EVENT structure

## Description

The WWAN_DEVICE_SERVICE_EVENT structure represents an unsolicited device service event.

## Members

### `DeviceServiceGuid`

The GUID of the device service that the event originated from.

### `EventID`

The ID for the event.

### `uDataSize`

The size, in bytes, of the device service event data that follows the structure instance in memory. This value should not exceed the value of the **uMaxCommandDataSize** member of the [WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services) structure.

## See also

[WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services)