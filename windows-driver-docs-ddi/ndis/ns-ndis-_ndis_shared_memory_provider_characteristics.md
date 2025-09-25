# _NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS structure

## Description

The NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS structure specifies shared memory provider
characteristics.

## Members

### `Header`

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
structure (NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS). The driver sets the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_SHARED_MEMORY_PROVIDER_CHARACTERISTICS, the
**Revision** member to NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_SHARED_MEMORY_PROVIDER_CHARACTERISTICS_REVISION_1.

### `Flags`

Reserved for NDIS.

### `ProviderContext`

An NDIS_HANDLE to a block of driver-allocated context information that stores information about
the provider. NDIS passes the context information in calls to
*NetXxxSharedMemory* functions at the
*ProviderContext* parameter.

### `AllocateSharedMemoryHandler`

An entry point for the
[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler) function.

### `FreeSharedMemoryHandler`

An entry point for the
[NetFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-free_shared_memory_handler) function.

## Remarks

To specify entry points for shared memory services, an NDIS driver initializes an
NDIS_SHARED_MEMORY_PROVIDER_CHARACTERISTICS structure and passes it to the
[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers) function.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NdisSetOptionalHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndissetoptionalhandlers)

[NetAllocateSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-allocate_shared_memory_handler)

[NetFreeSharedMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-free_shared_memory_handler)