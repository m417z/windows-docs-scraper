# _NDIS_WWAN_MPDP_LIST structure

## Description

The **NDIS_WWAN_MPDP_LIST** structure contains a list of existing Multiple Packet Data Protocol (MPDP) interfaces for the mobile broadband device representing the primary PDP context/EPS bearer.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_MPDP_LIST** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for *set* operations. Miniport drivers must set the header with the same values when they send the data structure to the MBB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_MPDP_LIST_REVISION_1 |
| Size | `sizeof(NDIS_WWAN_MPDP_LIST)` |

### `uStatus`

A **WWAN_STATUS** value that indicates the result of the query request.

### `ChildInterfaceList`

If **uStatus** == WWAN_STATUS_SUCCESS, this field contains a list of the existing MPDP interfaces. The **ElementType** member of this list header must be **WwanStructMPDPChildInterface**, and the **ElementCount** member of interface GUIDs must follow this header.

## Remarks

This structure is used in an [NDIS_STATUS_WWAN_MPDP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-mpdp-list) status indication, which is sent as an asynchronous response to an [OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp) query request.

## See also

[NDIS_STATUS_WWAN_MPDP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-mpdp-list)

[OID_WWAN_MPDP](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-mpdp)