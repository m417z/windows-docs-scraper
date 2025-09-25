# _NET_BUFFER_HEADER structure

## Description

The NET_BUFFER_HEADER structure specifies header information for the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure.

## Members

### `NetBufferData`

A
[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data) structure.

### `Link`

Reserved for NDIS.

## Remarks

NDIS maintains the information in the NET_BUFFER_HEADER union.

## See also

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_data)