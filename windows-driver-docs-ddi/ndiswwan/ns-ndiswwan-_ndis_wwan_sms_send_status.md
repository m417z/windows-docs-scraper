# _NDIS_WWAN_SMS_SEND_STATUS structure

## Description

The NDIS_WWAN_SMS_SEND_STATUS structure represents the status of a sent SMS text message.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SMS_SEND_STATUS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SMS_SEND_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SMS_SEND_STATUS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the SMS send operation.

### `MessageReference`

A reference number that is returned upon successful delivery of the SMS text message. This member
is populated by the device only if
**uStatus** member is set to WWAN_STATUS_SUCCESS.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)