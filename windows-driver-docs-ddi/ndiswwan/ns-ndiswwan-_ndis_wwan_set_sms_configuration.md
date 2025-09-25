# _NDIS_WWAN_SET_SMS_CONFIGURATION structure

## Description

The NDIS_WWAN_SET_SMS_CONFIGURATION structure represents the SMS configuration of the MB
device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_SMS_CONFIGURATION
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_SMS_CONFIGURATION_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_SMS_CONFIGURATION) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetSmsConfiguration`

A formatted
[WWAN_SET_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sms_configuration) object that represents the SMS configuration to set on the
device.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SET_SMS_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_sms_configuration)