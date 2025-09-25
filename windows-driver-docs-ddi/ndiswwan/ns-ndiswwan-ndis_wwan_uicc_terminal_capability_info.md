## Description

The **NDIS_WWAN_UICC_TERMINAL_CAPABILITY_INFO** structure represents information about the terminal capabilities of the host.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_UICC_TERMINAL_CAPABILITY_INFO** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_UICC_TERMINAL_CAPABILITY_INFO_REVISION_1|
|Size|sizeof(NDIS_WWAN_UICC_TERMINAL_CAPABILITY_INFO)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the operation.

### `UiccCapabilityInfo`

A [**WWAN_UICC_TERMINAL_CAPABILITY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_uicc_terminal_capability_info) structure.

## Remarks

## See also

[**WWAN_UICC_TERMINAL_CAPABILITY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_uicc_terminal_capability_info)

[OID_WWAN_UICC_TERMINAL_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-terminal-capability)