# NdisGetPoolFromNetBuffer function

## Description

Call the
**NdisGetPoolFromNetBuffer** function to get the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure pool handle that is associated
with a specified NET_BUFFER structure.

## Parameters

### `NetBuffer` [in]

A pointer to a previously allocated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Return value

**NdisGetPoolFromNetBuffer** returns a handle to the NET_BUFFER structure pool that is associated with
the specified NET_BUFFER structure.

## Remarks

The handle that
**NdisGetPoolFromNetBuffer** returns is a required parameter in calls to NDIS functions that manipulate
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are from the
associated NET_BUFFER structure pool.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)