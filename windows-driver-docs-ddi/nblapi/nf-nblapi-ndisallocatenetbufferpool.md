# NdisAllocateNetBufferPool function

## Description

Call the
**NdisAllocateNetBufferPool** function to allocate a pool of
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures.

## Parameters

### `NdisHandle` [in, optional]

An NDIS handle that was obtained during caller initialization.

### `Parameters` [in]

A pointer to a NET_BUFFER_POOL_PARAMETERS structure that defines the parameters for the pool. The
structure is defined as follows:

```
typedef struct _NET_BUFFER_POOL_PARAMETERS {
  NDIS_OBJECT_HEADER  Header;
  ULONG  PoolTag;
  ULONG  DataSize;
} NET_BUFFER_POOL_PARAMETERS, *PNET_BUFFER_POOL_PARAMETERS;
```

This structure includes the following members:

#### Header

The
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the
NET_BUFFER_POOL_PARAMETERS structure. Set the
**Type** member of the structure that
**Header** specifies to NDIS_OBJECT_TYPE_DEFAULT, the
**Revision** member to NET_BUFFER_POOL_PARAMETERS_REVISION_1, and the
**Size** member to NDIS_SIZEOF_NET_BUFFER_POOL_PARAMETERS_REVISION_1.

#### PoolTag

A kernel pool tag that the caller uses when it allocates
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures from this pool. The tag
is a string, delimited by single quotation marks, with up to four characters, usually specified in
reverse order. The kernel pool tag helps NDIS to identify the owner of the NET_BUFFER structures that
are allocated from this pool.

#### DataSize

The default data size for data buffers associated with this pool. The caller must set this value
if it calls the
[NdisAllocateNetBufferMdlAndData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffermdlanddata) function. NDIS uses this value to set the size of the data
buffer that it allocates for the NET_BUFFER structure. If the caller does not use this feature, this
value should be set to zero.

## Return value

**NdisAllocateNetBufferPool** returns a handle to the NET_BUFFER structure pool that NDIS allocates.
If the allocation was unsuccessful, this handle is **NULL**. This handle is a required parameter in
subsequent calls to NDIS functions that allocate and free NET_BUFFER structures from this pool.

## Remarks

Call the following functions to allocate
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures from the NET_BUFFER
structure pool.

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)

[NdisAllocateNetBufferMdlAndData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffermdlanddata)

**Note** [NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) and
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures must be allocated
from an NDIS buffer pool. A driver must not allocate and initialize a NET_BUFFER or NET_BUFFER_LIST
structure from its private memory pool or the stack.

You can call
**NdisAllocateNetBufferPool** and set the
**DataSize** value when creating a NET_BUFFER structure pool. In this case, MDL and data are
preallocated with each NET_BUFFER structure that the caller allocates from the pool. You must call the
**NdisAllocateNetBufferMdlAndData** function to allocate NET_BUFFER structures from such a pool.

MDL and data buffers that are allocated with
**NdisAllocateNetBufferMdlAndData** should not be freed separate from the NET_BUFFER structure. Such
structures are freed with the NET_BUFFER structure when you call the
[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer) function.

Call the
[NdisFreeNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferpool) function to
free NET_BUFFER structure pools that are created with
**NdisAllocateNetBufferPool**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NdisAllocateNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffer)

[NdisAllocateNetBufferMdlAndData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbuffermdlanddata)

[NdisFreeNetBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbuffer)

[NdisFreeNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreenetbufferpool)