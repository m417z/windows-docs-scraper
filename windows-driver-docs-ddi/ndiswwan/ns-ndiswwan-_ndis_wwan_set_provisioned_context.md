# _NDIS_WWAN_SET_PROVISIONED_CONTEXT structure

## Description

The NDIS_WWAN_SET_PROVISIONED_CONTEXT structure represents the command to set the provisioned context
state of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PROVISIONED_CONTEXT
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_PROVISIONED_CONTEXT_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_PROVISIONED_CONTEXT) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `ProvisionedContext`

A formatted
[WWAN_SET_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context) object that represents a
provisioned context.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)