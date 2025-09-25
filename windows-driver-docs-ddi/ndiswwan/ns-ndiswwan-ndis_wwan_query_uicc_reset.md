## Description

The **NDIS_WWAN_QUERY_UICC_RESET** structure represents the SIM slot ID that is associated with an [OID_WWAN_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-reset) query request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_QUERY_UICC_RESET** structure.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_QUERY_UICC_RESET_REVISION_1|
|Size|sizeof(NDIS_WWAN_QUERY_UICC_RESET)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `QueryUiccReset`

A [**WWAN_QUERY_UICC_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_uicc_reset) structure that represents the slot ID.

## Remarks

## See also

[OID_WWAN_UICC_RESET](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-reset)

[**WWAN_QUERY_UICC_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_uicc_reset)