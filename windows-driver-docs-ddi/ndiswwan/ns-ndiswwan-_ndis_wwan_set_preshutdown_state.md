# _NDIS_WWAN_SET_PRESHUTDOWN_STATE structure

## Description

The NDIS_WWAN_SET_PRESHUTDOWN_STATE structure represents the command to notify the modem to finish all operations and prepare to shut down.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PRESHUTDOWN_STATE
structure.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_PRESHUTDOWN_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_PRESHUTDOWN_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

## See also

[OID_WWAN_PRESHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preshutdown)