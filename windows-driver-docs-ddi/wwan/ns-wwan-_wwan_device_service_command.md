# _WWAN_DEVICE_SERVICE_COMMAND structure

## Description

The WWAN_DEVICE_SERVICE_COMMAND structure represents a device service command.

## Members

### `DeviceServiceGuid`

The GUID of the device service that the command targets.

### `CommandID`

The ID for the command.

### `uDataSize`

The size, in bytes, of the device service command data that follows the structure instance in memory. This value should not exceed the value of the **uMaxCommandDataSize** member of the [WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services) structure.

## Remarks

Device service command OIDs use this structure.

## See also

[WWAN_SUPPORTED_DEVICE_SERVICES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_supported_device_services)