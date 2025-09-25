# _NDIS_WWAN_SMS_STATUS structure

## Description

The NDIS_WWAN_SMS_STATUS structure represents the status of the SMS message store.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SMS_STATUS structure. The
MB Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SMS_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SMS_STATUS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the SMS operation.

### `SmsStatus`

A formatted
[WWAN_SMS_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_status) object that represents the
status of the SMS message store.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SMS_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_status)