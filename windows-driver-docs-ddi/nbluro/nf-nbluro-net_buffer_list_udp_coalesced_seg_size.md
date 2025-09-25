## Description

NDIS drivers use the **NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE** macro to get and set the size, in bytes, of the individual UDP datagram payloads that were coalesced into a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure. The datagrams must have the same payload length in order to be eligible for coalescing, with the exception of the last datagram which may be less.

## Syntax

```cpp
#define NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE(_NBL) \
    (((NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO*) \
        &(_NBL)->NetBufferListInfo[UdpRecvSegCoalesceOffloadInfo])->Receive.SegSize)
```

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

**NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE** returns the **SegSize** member of the [**NDIS_UDP_RSC_OFFLOAD_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbluro/ns-nbluro-ndis_udp_rsc_offload_net_buffer_list_info) structure that is associated with the **UdpRecvSegCoalesceOffloadInfo** identifier. The information is retrieved from the **NetBufferListInfo** member of the indicated **NET_BUFFER_LIST** structure.

## Remarks

The following example demonstrates getting a **SegSize** value:

```cpp
value = NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE(Nbl);
```

The following example demonstrates setting a **SegSize** value:

```cpp
NET_BUFFER_LIST_UDP_COALESCED_SEG_SIZE(Nbl) = 1200;
```

## See also

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)

[UDP Receive Segment Coalescing Offload (URO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-rsc-offload)