# _NDIS_WWAN_MPDP_STATE structure

## Description

The **NDIS_WWAN_MPDP_STATE** structure represents the state of a Multiple Packet Data Protocol (MPDP) interface after a requested operation.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_MPDP_STATE** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for *set* operations. Miniport drivers must set the header with the same values when they send the data structure to the MBB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_MPDP_STATE_REVISION_1 |
| Size | `sizeof(NDIS_WWAN_MPDP_STATE)` |

### `uStatus`

A **WWAN_STATUS** value that indicates the result of the requested MPDP interface operation.

### `Info`

A formatted [**NDIS_WWAN_MPDP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_info) structure that contains information about the requested MPDP operation.

## Remarks

This structure is used in an [NDIS_STATUS_WWAN_MPDP_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-mpdp-state) status indication, which is sent as an asynchronous response to an [OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp) set request.

## See also

[**NDIS_WWAN_MPDP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_info)

[NDIS_STATUS_WWAN_MPDP_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-mpdp-state)

[OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp)