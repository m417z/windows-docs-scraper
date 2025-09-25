# _NDIS_WWAN_MAC_PARAMETERS structure

## Description

The NDIS_WWAN_MAC_PARAMETERS structure is used by [OID_WWAN_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-create-mac) when processing a request to create an NDIS port for a new PDP context.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_MAC_PARAMETERS structure.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_MAC_PARAMETERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_MAC_PARAMETERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

## See also

[OID_WWAN_CREATE_MAC](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-create-mac)