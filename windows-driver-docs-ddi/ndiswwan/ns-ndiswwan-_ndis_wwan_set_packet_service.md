# _NDIS_WWAN_SET_PACKET_SERVICE structure

## Description

The NDIS_WWAN_SET_PACKET_SERVICE structure represents the packet service state of the MB
device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PACKET_SERVICE
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_PACKET_SERVICE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_PACKET_SERVICE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PacketServiceAction`

A value from the
[WWAN_PACKET_SERVICE_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_packet_service_action) enumeration that represents the packet service action to take.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_PACKET_SERVICE_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_packet_service_action)