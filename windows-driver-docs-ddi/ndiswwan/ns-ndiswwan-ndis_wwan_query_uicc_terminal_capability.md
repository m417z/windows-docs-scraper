## Description

The **NDIS_WWAN_QUERY_UICC_TERMINAL_CAPABILITY** structure represents the SIM slot ID that is associated with an [OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability) query request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_QUERY_UICC_TERMINAL_CAPABILITY** structure.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_QUERY_UICC_TERMINAL_CAPABILITY_REVISION_1|
|Size|sizeof(NDIS_WWAN_QUERY_UICC_TERMINAL_CAPABILITY)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `QueryUiccTerminalCapability`

A [**WWAN_QUERY_UICC_TERMINAL_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_uicc_terminal_capability) structure that represents the slot ID.

## Remarks

## See also

[OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability)

[**WWAN_QUERY_UICC_TERMINAL_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_query_uicc_terminal_capability)