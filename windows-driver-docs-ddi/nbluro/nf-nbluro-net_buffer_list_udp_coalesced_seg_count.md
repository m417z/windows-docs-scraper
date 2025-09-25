## Description

The **NET_BUFFER_LIST_UDP_COALESCED_SEG_COUNT** macro returns the number of segments that were coalesced into a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_UDP_COALESCED_SEG_COUNT** returns the **SegCount** member of the [**NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload_net_buffer_list_info) structure that is associated with the **UdpRecvSegCoalesceOffloadInfo** identifier. The information is retrieved from the **NetBufferListInfo** member of the indicated NET_BUFFER_LIST structure.

## Remarks

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[**NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload_net_buffer_list_info)

[UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload)