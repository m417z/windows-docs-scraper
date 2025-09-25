# _NDIS_GENERIC_OBJECT structure

## Description

The NDIS_GENERIC_OBJECT structure defines a generic object which a software component can use to
obtain an NDIS handle.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
generic object structure (NDIS_GENERIC_OBJECT). NDIS sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_GENERIC_OBJECT, the
**Revision** member to NDIS_GENERIC_OBJECT_REVISION_1, and the
**Size** member to
sizeof(NDIS_GENERIC_OBJECT).

### `Caller`

Reserved for NDIS.

### `CallersCaller`

Reserved for NDIS.

### `DriverObject`

The driver object that is associated with the generic object. If there is no driver object, this
member is **NULL**. This is the value passed at the
*DriverObject* parameter of the
[NdisAllocateGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocategenericobject) function.

## Remarks

Software components that do not already have an NDIS handle call
[NdisAllocateGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocategenericobject) to
create a generic object. Such components use the handle obtained from
**NdisAllocateGenericObject** to allocate NDIS resources.

The
*Size* parameter of
**NdisAllocateGenericObject** specifies an amount of memory, in bytes, to reserve for the caller.
**NdisAllocateGenericObject** adds the additional memory after the NDIS_OBJECT_STRUCTURE members.

Most NDIS drivers do not require a generic object to get a handle. NDIS protocol, intermediate, and
miniport drivers obtain a handle during initialization.

Use the
[NdisFreeGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreegenericobject) function to
free a generic object that was created with
**NdisAllocateGenericObject**.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisAllocateGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocategenericobject)

[NdisFreeGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreegenericobject)