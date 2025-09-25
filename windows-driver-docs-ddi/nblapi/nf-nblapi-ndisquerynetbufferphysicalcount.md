# NdisQueryNetBufferPhysicalCount function

## Description

The
**NdisQueryNetBufferPhysicalCount** function returns the maximum number of physical breaks mapped by the
buffer descriptors that are associated with the given
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Parameters

### `NetBuffer` [in]

A pointer to a previously allocated
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Return value

**NdisQueryNetBufferPhysicalCount** returns a ULONG value containing a count of the maximum number of
physical breaks, mapped by MDLs that are associated with the specified NET_BUFFER structure.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)