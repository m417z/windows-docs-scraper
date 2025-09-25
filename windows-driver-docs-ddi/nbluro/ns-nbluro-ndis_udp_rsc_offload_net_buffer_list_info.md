## Description

The **NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO** structure specifies the [UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload) information for a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Members

### `Receive`

A structure that contains the UDP RSC offload information.

### `Receive.SegCount`

The number of segments that were coalesced into the NET_BUFFER_LIST structure.

### `Receive.SegSize`

The size, in bytes, of the individual segments that were coalesced into the NET_BUFFER_LIST structure.

### `Value`

A PVOID version of the UDP RSC information. Miniport drivers can use this member to access the raw information instead of the specific fields.

## Remarks

The **NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO** structure is part of the information that is included in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload)