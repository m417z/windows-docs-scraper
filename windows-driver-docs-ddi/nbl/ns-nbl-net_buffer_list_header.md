# _NET_BUFFER_LIST_HEADER structure

## Description

The NET_BUFFER_LIST_HEADER defines header information for the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `NetBufferListData`

A
[NET_BUFFER_LIST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_data) structure.

### `Link`

Reserved for NDIS.

## Remarks

NDIS maintains the information in the NET_BUFFER_LIST_HEADER union.

## See also

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[NET_BUFFER_LIST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list_data)