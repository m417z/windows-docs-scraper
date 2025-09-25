# _WWAN_DEVICE_SERVICE_SESSION structure

## Description

The WWAN_DEVICE_SERVICE_SESSION structure represents the state of a device service session, or the operation to be performed on a device service.

## Members

### `DeviceServiceGuid`

The GUID of the device service on which to perform the operation.

### `State`

The state of, or action, for the device service session.

### `uSessionID`

The session ID for the device service session.

## See also

[NDIS_WWAN_DEVICE_SERVICE_SESSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_service_session_info)

[NDIS_WWAN_SET_DEVICE_SERVICE_SESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_device_set_service_session)

[WWAN_DEVICE_SERVICE_SESSION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_device_service_session_state)