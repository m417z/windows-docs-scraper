## Description

The **NDIS_WWAN_ATR_INFO** structure represents a SIM card's Answer to Reset (ATR) information.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_ATR_INFO** structure.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_ATR_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_ATR_INFO) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

A **WWAN_STATUS** value that indicates the result of the query request.

### `AtrInfo`

A [**WWAN_ATR_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_atr_info) structure that represents the ATR information.

## Remarks

## See also

[**WWAN_ATR_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_atr_info)

[OID_WWAN_UICC_ATR](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-atr)

[NDIS_STATUS_WWAN_ATR_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-atr-info)