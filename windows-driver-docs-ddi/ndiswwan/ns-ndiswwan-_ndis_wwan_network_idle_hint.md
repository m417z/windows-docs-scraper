# _NDIS_WWAN_NETWORK_IDLE_HINT structure

## Description

The NDIS_WWAN_NETWORK_IDLE_HINT structure contains a hint for the network interface regarding whether data is expected to be active or idle on the interface.

## Members

### `Header`

The type, revision, and size of the NDIS_WWAN_NETWORK_IDLE_HINT structure. This member is
formatted as an
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of
**Header** to the following values:

| Member | Setting |
| --- | --- |
| **Type** | NDIS_OBJECT_TYPE_DEFAULT |
| **Revision** | NDIS_WWAN_NETWORK_IDLE_HINT_REVISION_1 |
| **Size** | SIZEOF_NDIS_WWAN_NETWORK_IDLE_HINT_1 |

### `IdleHint`

A formatted [WWAN_NETWORK_IDLE_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_idle_hint) object that contains the network idle hint.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_WWAN_NETWORK_IDLE_HINT](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-network-idle-hint)

[WWAN_NETWORK_IDLE_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_idle_hint)