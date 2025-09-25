# _NDIS_PD_OPEN_PROVIDER_PARAMETERS structure

## Description

This structure is used as a buffer for parameters in the [OID_PD_OPEN_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pd-open-provider) OID.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_OPEN_PROVIDER_PARAMETERS** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_OPEN_PROVIDER_PARAMETERS_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_OPEN_PROVIDER_PARAMETERS_REVISION_1**

### `Flags`

This member is reserved and must be 0.

### `ProviderHandle`

A provider handle that identifies the PD-capable miniport driver's provider object.

### `ProviderDispatch`

See [NDIS_PD_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_provider_dispatch).

## Remarks

This structure must be aligned on an 8-byte boundary.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)