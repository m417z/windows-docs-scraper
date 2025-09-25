# _WWAN_DEVICE_SERVICE_SESSION_CAPABILITY enumeration

## Description

The WWAN_DEVICE_SERVICE_SESSION_CAPABILITY enumeration lists the different device service session operations that are supported by the device service.

## Constants

### `WwanDeviceServiceSessionNotSupported`

The device service does not support device service sessions.

### `WwanDeviceServiceSessionWriteSupported`

The device service supports write operations from Windows to the miniport driver.

### `WwanDeviceServiceSessionReadSupported`

The device service supports read indication notifications on a session for data read from the device.

## See also

[WWAN_DEVICE_SERVICE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_entry)