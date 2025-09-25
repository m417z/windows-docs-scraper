# _WWAN_DEVICE_SERVICE_ENTRY structure

## Description

The WWAN_DEVICE_SERVICE_ENTRY structure describes information about a device service.

## Members

### `DeviceServiceGuid`

The GUID of the device service. This GUID is used to identify the device service in any of the other device OIDs/indications.

### `SessionCapability`

Flags indicating the capabilities of a device service session.

### `uMaxSessionInstances`

The maximum number of sessions supported by the device service.

## Remarks

Device service OIDs and NDIS Status Notifications use the device service's GUID to identify the device service.

## See also

[WWAN_DEVICE_SERVICE_SESSION_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_device_service_session_capability)