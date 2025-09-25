# _NDIS_WWAN_SMS_READ structure

## Description

The NDIS_WWAN_SMS_READ structure represents an SMS message to read.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SMS_READ structure. The
MB Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SMS_READ_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SMS_READ) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SmsRead`

A formatted
[WWAN_SMS_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_read) object that represents the
format and filter of SMS messages to read.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_SMS_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_read)