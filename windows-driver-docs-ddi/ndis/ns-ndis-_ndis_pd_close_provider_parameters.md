# _NDIS_PD_CLOSE_PROVIDER_PARAMETERS structure

## Description

This structure represents the parameters that are used when calling the [OID_PD_CLOSE_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pd-close-provider) OID.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the **NDIS_PD_CLOSE_PROVIDER_PARAMETERS** structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_CLOSE_PROVIDER_PARAMETERS_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_CLOSE_PROVIDER_PARAMETERS_REVISION_1**

### `Flags`

This member is reserved and must be set to 0.

### `ProviderHandle`

A provider handle that identifies the PD-capable miniport driver's provider object.

## Remarks

This structure must be aligned on an 8-byte boundary.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_PD_CLOSE_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-pd-close-provider)