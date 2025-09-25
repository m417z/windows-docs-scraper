## Description

The **NDIS_WWAN_SET_UICC_TERMINAL_CAPABILITY** structure represents the terminal capabilities of the host and SIM slot ID associated with an [OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability) set request.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_UICC_TERMINAL_CAPABILITY** structure.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_SET_UICC_TERMINAL_CAPABILITY_REVISION_1|
|Size|sizeof(NDIS_WWAN_SET_UICC_TERMINAL_CAPABILITY)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetUiccTerminalCapability`

A [**WWAN_SET_UICC_TERMINAL_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_set_uicc_terminal_capability) structure.

## Remarks

## See also

[**WWAN_SET_UICC_TERMINAL_CAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_set_uicc_terminal_capability)

[OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability)

[NDIS_STATUS_WWAN_UICC_TERMINAL_CAPABILITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-uicc-terminal-capability-info)