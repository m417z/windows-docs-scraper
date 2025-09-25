# _NDIS_WWAN_SET_PREFERRED_MULTICARRIER_PROVIDERS structure

## Description

The NDIS_WWAN_SET_PREFERRED_MULTICARRIER_PROVIDERS structure represents a list of preferred multicarrier providers associated with the MB device.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_PREFERRED_MULTICARRIER_PROVIDERS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_PREFERRED_MULTICARRIER_PROVIDERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_PREFERRED_MULTICARRIER_PROVIDERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PreferredListHeader`

A formatted
[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a
list of preferred multicarrier providers to associate with the MB device.

## See also

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)