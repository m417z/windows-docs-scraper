# NdisAllocateGenericObject function

## Description

Components that do not have an NDIS handle use the
**NdisAllocateGenericObject** function to allocate a generic NDIS object.

## Parameters

### `DriverObject` [optional]

A driver object to associate with the generic object. This parameter can be **NULL**.

### `Tag`

The kernel memory tag that NDIS should use to allocate memory for the generic object.

### `Size`

The amount of memory, in bytes, to reserve for the caller. This does not include the size of the
[NDIS_GENERIC_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_generic_object) structure. Use the
additional memory space for your own purposes. To access the additional memory, use
sizeof(NDIS_GENERIC_OBJECT) to skip over the generic object structure.

## Return value

**NdisAllocateGenericObject** returns a pointer to the NDIS_GENERIC_OBJECT that it allocated. If NDIS
failed to create the object, the return value is **NULL**.

## Remarks

NDIS uses a generic object to manage resources that are allocated by a component that does not
otherwise have an NDIS handle. Such a component uses the returned generic object pointer as an NDIS
handle in some NDIS resource allocation APIs that require an NDIS handle.

NDIS drivers must call the
[NdisFreeGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreegenericobject) function to
free a generic object that was created with
**NdisAllocateGenericObject**.

## See also

[NDIS_GENERIC_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_generic_object)

[NdisFreeGenericObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreegenericobject)