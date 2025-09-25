# _NDIS_WWAN_GET_VISIBLE_PROVIDERS structure

## Description

The NDIS_WWAN_GET_VISIBLE_PROVIDERS structure is used to request the miniport driver get either all visible providers or only multi-carrier visible providers.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_GET_VISIBLE_PROVIDERS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_GET_VISIBLE_PROVIDERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_GET_VISIBLE_PROVIDERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `VisibleProviders`

A formatted WWAN_GET_VISIBLE_PROVIDERS object that provides additional information to the miniport about the type of providers to return.

## See also

[WWAN_GET_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_get_visible_providers)