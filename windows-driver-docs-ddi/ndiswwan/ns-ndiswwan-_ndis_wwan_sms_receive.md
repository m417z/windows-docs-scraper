# _NDIS_WWAN_SMS_RECEIVE structure

## Description

The NDIS_WWAN_SMS_RECEIVE structure represents a list of received SMS messages and the number of
messages in the list.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SMS_RECEIVE structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SMS_RECEIVE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SMS_RECEIVE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the SMS receive operation.

### `SmsListHeader`

A formatted
[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a
list of received SMS messages and the number of messages in the list.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)