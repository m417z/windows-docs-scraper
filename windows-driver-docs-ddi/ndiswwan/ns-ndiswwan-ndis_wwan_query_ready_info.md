## Description

The **NDIS_WWAN_QUERY_READY_INFO** structure represents the SIM slot ID that is associated with an [OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info) query request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_QUERY_READY_INFO** structure.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_QUERY_READY_INFO_REVISION_1|
|Size|sizeof(NDIS_WWAN_QUERY_READY_INFO)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `QueryReadyInfo`

A [**WWAN_QUERY_READY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_ready_info) structure that represents the slot ID.

## Remarks

## See also

[**WWAN_QUERY_READY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_ready_info)

[OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info)