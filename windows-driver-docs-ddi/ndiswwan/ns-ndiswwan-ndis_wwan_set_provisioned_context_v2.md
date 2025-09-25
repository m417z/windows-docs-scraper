## Description

The **NDIS_WWAN_SET_PROVISIONED_CONTEXT_V2** structure represents the command to set the provisioned context state of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PROVISIONED_CONTEXT_V2 structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

|Header submember|Value|
|---|---|
|Type|NDIS_OBJECT_TYPE_DEFAULT|
|Revision|NDIS_WWAN_SET_PROVISIONED_CONTEXT_REVISION_2|
|Size|sizeof(NDIS_WWAN_SET_PROVISIONED_CONTEXT_V2)|

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ProvisionedContext`

A formatted [**WWAN_SET_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_set_provisioned_context_v2) object that represents a provisioned context.

## Remarks

## See also

[**WWAN_SET_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_set_provisioned_context_v2)