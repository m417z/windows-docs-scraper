# _NDIS_WWAN_PRESHUTDOWN_STATE structure

## Description

The NDIS_WWAN_PRESHUTDOWN_STATE structure contains the pre-shutdown status.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PRESHUTDOWN_STATE
structure.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PRESHUTDOWN_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PRESHUTDOWN_STATE) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The following table shows the possible status codes.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | Pre-shutdown operations are complete and the host can power down the MBB driver. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The modem does not support pre-shutdown notifications. |

## See also

[NDIS_STATUS_WWAN_PRESHUTDOWN_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-preshutdown-state)

[OID_WWAN_PRESHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preshutdown)