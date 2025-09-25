# _NDIS_WWAN_HOME_PROVIDER2 structure

## Description

The NDIS_WWAN_HOME_PROVIDER2 structure describes details of a home network provider.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_HOME_PROVIDER2 structure. The MB
Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_HOME_PROVIDER_REVISION_2 |
| Size | sizeof(NDIS_WWAN_HOME_PROVIDER2) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of the home provider operation.

### `Provider`

A formatted [WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2) object that describes the details of a home network provider.

## See also

[WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2)