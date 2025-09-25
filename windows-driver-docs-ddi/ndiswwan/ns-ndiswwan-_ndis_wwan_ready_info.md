# _NDIS_WWAN_READY_INFO structure

## Description

The NDIS_WWAN_READY_INFO structure represents the ready-state of the MB device and Subscriber
Identity Module (SIM card).

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_READY_INFO structure. The
MB Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_READY_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_READY_INFO) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ReadyInfo`

A formatted
[WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ready_info) object that represents the
device ready-state.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ready_info)