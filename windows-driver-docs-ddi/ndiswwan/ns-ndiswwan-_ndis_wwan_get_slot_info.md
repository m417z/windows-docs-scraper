# _NDIS_WWAN_GET_SLOT_INFO structure

## Description

The **NDIS_WWAN_GET_SLOT_INFO** structure represents the status of a slot in the modem of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_GET_SLOT_INFO** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_GET_SLOT_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_GET_SLOT_INFO) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `GetSlotInfo`

A formatted [WWAN_GET_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_get_slot_info) structure which contains the slot index to specify which slot's status the query request is for.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_GET_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_get_slot_info)