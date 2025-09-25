# _NDIS_WWAN_SET_HOME_PROVIDER structure

## Description

The NDIS_WWAN_SET_HOME_PROVIDER structure describes a home provider.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_SET_HOME_PROVIDER structure. The MB
Service sets the header with the values that are shown in the following table when it sends the data
structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_HOME_PROVIDER_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_HOME_PROVIDER) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `HomeProvider`

A formatted WWAN_PROVIDER2 object that represents the details of the home provider to be set.

## See also

[WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2)