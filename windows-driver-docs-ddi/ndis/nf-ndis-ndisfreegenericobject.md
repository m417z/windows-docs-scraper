# NdisFreeGenericObject function

## Description

Call the
**NdisFreeGenericObject** function to free a generic object that was created with the
[NdisAllocateGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocategenericobject) function.

## Parameters

### `NdisObject`

A pointer to the
[NDIS_GENERIC_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_generic_object) structure to be
freed.

## Remarks

An NDIS handle is required to allocate some NDIS resources (for example, buffer pools). Components
that do not otherwise have an NDIS handle use a pointer to an
[NDIS_GENERIC_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_generic_object) structure as an NDIS
handle. All resources that were allocated with this generic object pointer as the handle must be freed
before freeing the generic object.

## See also

[NDIS_GENERIC_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_generic_object)

[NdisAllocateGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocategenericobject)