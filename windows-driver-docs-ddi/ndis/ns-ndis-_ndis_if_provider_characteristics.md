# _NDIS_IF_PROVIDER_CHARACTERISTICS structure

## Description

The NDIS_IF_PROVIDER_CHARACTERISTICS structure defines NDIS network interface provider entry points
and other provider characteristics.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
interface provider characteristics structure (NDIS_IF_PROVIDER_CHARACTERISTICS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NDIS_OBJECT_REVISION_1, and the
**Size** member to NDIS_SIZEOF_IF_PROVIDER_CHARACTERISTICS_REVISION_1.

### `QueryObjectHandler`

The entry point for the
[ProviderQueryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-if_query_object) function.

### `SetObjectHandler`

The entry point for the
[ProviderSetObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-if_set_object) function.

### `Reserved1`

Reserved for NDIS.

### `Reserved2`

Reserved for NDIS.

## Remarks

All NDIS network driver types can register as network interface providers. An NDIS interface provider
initializes an NDIS_IF_PROVIDER_CHARACTERISTICS structure to define its provider entry points and other
characteristics, if any.

To register as an interface provider, the driver passes a pointer to the initialized
NDIS_IF_PROVIDER_CHARACTERISTICS structure to the
[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisIfRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisifregisterprovider)

[ProviderQueryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-if_query_object)

[ProviderSetObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-if_set_object)