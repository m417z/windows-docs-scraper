# NdisGetPoolFromNetBufferList function

## Description

Call the
**NdisGetPoolFromNetBufferList** function to get the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure pool handle that is
associated with a specified NET_BUFFER_LIST structure.

## Parameters

### `NetBufferList` [in]

A pointer to a previously allocated
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Return value

**NdisGetPoolFromNetBufferList** returns a handle to the NET_BUFFER_LIST structure pool that is
associated with the specified NET_BUFFER_LIST structure.

## Remarks

The handle that
**NdisGetPoolFromNetBufferList** returns is a required parameter in calls to NDIS functions that
manipulate the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structures that are from the
associated NET_BUFFER_LIST structure pool.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)