# _NET_BUFFER_LIST_DATA structure

## Description

The NET_BUFFER_LIST_DATA structure contains management data for the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structures that are linked to a
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Next`

A pointer to the next NET_BUFFER_LIST structure in a linked list of NET_BUFFER_LIST structures. If
this structure is the last NET_BUFFER_LIST structure in the list, this member is **NULL**.

### `FirstNetBuffer`

A pointer to the first
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in the linked list of
NET_BUFFER structures.

## Remarks

The
[NET_BUFFER_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_list_header) structure
contains a NET_BUFFER_LIST_DATA structure.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_net_buffer_list_header)