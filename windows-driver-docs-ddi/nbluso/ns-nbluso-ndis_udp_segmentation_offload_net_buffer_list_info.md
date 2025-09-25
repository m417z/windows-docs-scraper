# _NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO structure

## Description

The **NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO** structure specifies information that is used in offloading UDP Segmentation Offload (USO) tasks from the TCP/IP transport to a miniport adapter. The **NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO** structure is part of the [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) OOB information.

## Members

### `Transmit`

A structure that contains individual bit fields for USO information.

### `Transmit.MSS`

The maximum segment size (MSS), in bytes, for each UDP segment. The TCP/IP transport writes this value before passing a large UDP packet to a miniport driver for segmentation.

### `Transmit.UdpHeaderOffset`

The offset, in bytes, of the UDP header from the beginning of the packet for UDP packets. Miniport drivers can use **UdpHeaderOffset** to determine the location of the UDP header so that they do not have to parse IP headers.

### `Transmit.Reserved`

Reserved. Miniport drivers must not read or write to this value.

### `Transmit.IPVersion`

The IP version of the packet. For IPv4 packets, **IPVersion** is set to NDIS_UDP_SEGMENTATION_OFFLOAD_IPV4. For IPv6 packets, **IPVersion** is set to NDIS_UDP_SEGMENTATION_OFFLOAD_IPV6.

### `Value`

A PVOID version of the USO information. Miniport drivers can use this member to access the raw information instead of the specific fields.

## Remarks

The **NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO** structure is part of the information that is included in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

To set and get USO information, use the **UdpSegmentationOffloadInfo** index with the [**NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nblaccessors/nf-nblaccessors-net_buffer_list_info) macro. **NET_BUFFER_LIST_INFO** returns a ULONG value (not a pointer to a ULONG value).

The TCP/IP transport updates the **MSS** and **UdpHeaderOffset** members of the **NDIS_UDP_SEGMENTATION_OFFLOAD_NET_BUFFER_LIST_INFO** structure before sending a large packet to a miniport driver.

>[!NOTE]
> Any **NET_BUFFER_LIST** structure that contains USO information also contains a single **NET_BUFFER** structure.

## See also

[UDP Segmentation Offload (USO)](https://learn.microsoft.com/windows-hardware/drivers/network/udp-segmentation-offload-uso-)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)