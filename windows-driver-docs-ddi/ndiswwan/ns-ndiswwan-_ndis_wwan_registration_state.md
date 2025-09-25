# _NDIS_WWAN_REGISTRATION_STATE structure

## Description

The NDIS_WWAN_REGISTRATION_STATE structure represents the registration state of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_REGISTRATION_STATE
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | Windows 10, version 1903 miniport drivers that support a 5G device should set this to NDIS_WWAN_REGISTRATION_STATE_REVISION_3. Windows 8 miniport drivers should set this to NDIS_WWAN_REGISTRATION_STATE_REVISION_2. Windows 7 miniport drivers should set this to NDIS_WWAN_REGISTRATION_STATE_REVISION_1. |
| Size | sizeof(NDIS_WWAN_REGISTRATION_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

A miniport driver must set this to WWAN_STATUS_SUCCESS for unsolicited events
(NDIS_STATUS_INDICATION::RequestId = 0). WWAN_STATUS_SUCCESS is also set for successful execution of the
NDIS_WWAN_SET_REGISTER_STATE.

The following table shows the other possible error status codes.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_PIN_REQUIRED | Device requires PIN value input. |
| WWAN_STATUS_FAILURE | Unable to get registration state. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_BAD_SIM | The operation failed because a bad SIM card was detected. |
| WWAN_STATUS_SIM_NOT_INSERTED | The operation failed because the SIM card was not inserted fully into the device. |

Miniport drivers can return the following error codes (in addition to the above listed) only in the
event a PDP activation
*set* operation fails.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_FAILURE | Unable to set registration state. More information is specified in **uNwError** . For other error codes, **uNwError** should be set to 0. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | CDMA-based devices must return this error code, if a *set* registration request is for manual registration. |
| WWAN_STATUS_SERVICE_NOT_ACTIVATED | Service activation failed. Subscription expired. Device does not allow setting registration state. |
| WWAN_STATUS_PROVIDER_NOT_VISIBLE | Provider is not visible for registration. This is for manual registration. |
| WWAN_STATUS_INVALID_PARAMETERS | If the request is manual registration to a forbidden provider. |
| WWAN_STATUS_BUSY | The device is busy and unable to change the registration mode. This scenario can occur if the device does not permit changing the registration mode when a PDP context is activated. |

### `RegistrationState`

A formatted
[WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_registration_state) object that
represents the registration state of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_registration_state)