# _NDIS_WWAN_SMS_CONFIGURATION structure

## Description

The NDIS_WWAN_SMS_CONFIGURATION structure represents the SMS configuration of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SMS_CONFIGURATION
structure. When the MB Service
sends the data structure to the miniport driver for
*set* operations, it sets the header with the values that are shown in the following table. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SMS_CONFIGURATION_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SMS_CONFIGURATION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the SMS configuration operation. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_NOT_INITIALIZED | The operation failed because the device is in the process of initializing. Retry the operation after the ready-state of the device changes to **WwanReadyStateInitialized**. |
| WWAN_STATUS_PIN_REQUIRED | The operation failed because the device requires a PIN. |
| WWAN_STATUS_SIM_NOT_INSERTED | The operation failed because the SIM card was not inserted fully into the device. |
| WWAN_STATUS_BAD_SIM | The operation failed because a faulty SIM card was detected. |
| WWAN_STATUS_SMS_UNKNOWN_ERROR | The operation failed because of an unknown error. |
| WWAN_STATUS_SMS_FORMAT_NOT_SUPPORTED | The operation failed because the SMS format specified in [WWAN_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_configuration) is not supported. |

### `SmsConfiguration`

A formatted
[WWAN_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_configuration) object that
represents the SMS configuration of the MB device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_configuration)