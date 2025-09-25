# _NDIS_WWAN_SERVICE_ACTIVATION_STATUS structure

## Description

The NDIS_WWAN_SERVICE_ACTIVATION_STATUS structure represents the status of service activation on the
MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SERVICE_ACTIVATION_STATUS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SERVICE_ACTIVATION_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SERVICE_ACTIVATION_STATUS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the service activation operation. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Service activation succeeded. |
| WWAN_STATUS_INVALID_PARAMETERS | Service activation failed because of invalid parameters. |
| WWAN_STATUS_FAILURE | Service activation failed. Miniport drivers can return this value if service has already been activated. |
| WWAN_STATUS_PIN_REQUIRED | Service activation failed because the device requires a PIN. |
| WWAN_STATUS_RADIO_POWER_OFF | Service activation failed because the radio is currently turned off. |
| WWAN_STATUS_BAD_SIM | Service activation failed because a bad SIM card was detected. |
| WWAN_STATUS_SIM_NOT_INSERTED | Service activation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_PROVIDER_NOT_VISIBLE | Service activation failed because the service provider is not currently visible. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | Service activation failed because the device does not support service activation. |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to WwanReadyStateInitialized. |

### `ServiceActivationStatus`

A formatted
[WWAN_SERVICE_ACTIVATION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_service_activation_status) object that represents the status of service activation on the
device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SERVICE_ACTIVATION_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_service_activation_status)