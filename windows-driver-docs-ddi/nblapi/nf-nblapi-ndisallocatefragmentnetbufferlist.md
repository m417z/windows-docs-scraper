# NdisAllocateFragmentNetBufferList function

## Description

Call the
**NdisAllocateFragmentNetBufferList** function to create a new fragmented
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure based upon the data
in an existing NET_BUFFER_LIST structure.

## Parameters

### `OriginalNetBufferList` [in]

A pointer to an existing NET_BUFFER_LIST structure.

### `NetBufferListPool`

A handle that was obtained from a call to the
[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool) function.

### `NetBufferPool`

A NET_BUFFER structure pool handle that was previously returned from a call to
[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool).

### `StartOffset` [in]

An additional byte offset from the start of the data in each
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure. This offset is in addition
to the value of the
**DataOffset** member specified in each NET_BUFFER structure.

### `MaximumLength` [in]

The maximum length, in bytes, for each fragment in the new NET_BUFFER_LIST structure. Each
fragment is described by a NET_BUFFER structure.

### `DataOffsetDelta` [in]

The additional amount of
*used data space* that NDIS should make available in the new NET_BUFFER structures.

### `DataBackFill` [in]

The amount of data space in addition to the value of the
*DataOffsetDelta* parameter to allocate if allocation is necessary. If NDIS must allocate memory to
supply the data space requested in
*DataOffsetDelta*, it should also allocate the additional space that
*DataBackFill* specifies.

### `AllocateFragmentFlags` [in]

NDIS flags that can be combined with an OR operation. Set this parameter to zero. There are
currently no flags defined for this function.

## Return value

**NdisAllocateFragmentNetBufferList** returns a pointer to a new fragmented NET_BUFFER_LIST structure.
If the allocation failed, the return value is **NULL**.

## Remarks

**NdisAllocateFragmentNetBufferList** allocates and initializes a new fragment
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure and
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that describe the same data
that is described by the NET_BUFFER_LIST structure that the caller passed to
**NdisAllocateFragmentNetBufferList**.

If the fragment NET_BUFFER_LIST structure should have attributes that are associated with a given
pool, the caller must specify the pool handle in the
*NetBufferListPoolHandle* or
*NetBufferPoolHandle* parameter. For example, the
**ProtocolType** member of the NET_BUFFER_LIST structure is associated with the pool.

For each NET_BUFFER structure in the specified source NET_BUFFER_LIST structure, NDIS creates the
fragment NET_BUFFER structures as follows:

* NDIS creates the fragments starting from the beginning of the
  *used data space* in the source NET_BUFFER structure and offset by the value specified in the
  *StartOffset* parameter.
* NDIS divides the
  *used data space*(after accounting for the
  *StartOffset* ) in the source NET_BUFFER structure into fragments.
* The length of the
  *used data space* of each fragment is less than or equal to the value specified in the
  *MaximumLength* parameter. The
  *used data space* of the last fragment can be less than
  *MaximumLength* .
* Each fragment is described by a new NET_BUFFER structure and a new set of MDL chains.
* The data offset of the new NET_BUFFER structures is retreated (the value of the
  **DataOffset** member is reduced) by the number of bytes specified in the
  *DataOffsetDelta* parameter.
* If NDIS must allocate memory to supply the data space requested in
  *DataOffsetDelta*, it should also allocate the additional space that
  *DataBackFill* specifies.

The new fragment NET_BUFFER_LIST structure that
**NdisAllocateFragmentNetBufferList** creates does not include an initial
[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context) structure.

Call the
[NdisFreeFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreefragmentnetbufferlist) function to free a NET_BUFFER_LIST structure and all associated
NET_BUFFER structures and MDL chains that were previously allocated by calling
**NdisAllocateFragmentNetBufferList**.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_context)

[NdisAllocateNetBufferListPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblapi/nf-nblapi-ndisallocatenetbufferlistpool)

[NdisAllocateNetBufferPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatenetbufferpool)

[NdisFreeFragmentNetBufferList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreefragmentnetbufferlist)