# _NDIS_WWAN_SET_MPDP_STATE structure

## Description

The **NDIS_WWAN_SET_MPDP_STATE** structure contains information for performing an operation on a Multiple Packet Data Protocol (MPDP) interface.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_MPDP_STATE** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for *set* operations. Miniport drivers must set the header with the same values when they send the data structure to the MBB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_MPDP_STATE_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_MPDP_STATE) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `Info`

A formatted [**NDIS_WWAN_MPDP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_info) structure that contains the information for the miniport driver to use in the MPDP interface operation.

## Remarks

This structure is used in an [OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp) set request.

## See also

[**NDIS_WWAN_MPDP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_mpdp_info)

[OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp)