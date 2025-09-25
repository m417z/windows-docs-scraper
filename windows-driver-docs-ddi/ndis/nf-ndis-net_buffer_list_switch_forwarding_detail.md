# NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL macro

## Description

Hyper-V extensible switch extensions use the **NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL** macro to access the [**NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) union in the extensible switch context area in a [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

## Parameters

### `_NBL`

A pointer to a **NET_BUFFER_LIST** structure.

## Return value

The **NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL** macro returns a pointer to the [**NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) union within the specified [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure.

> [!NOTE]
> **NET_BUFFER_LIST_SWITCH_FORWARDING_DETAIL** returns **NULL** if the [**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure does not contain an [**NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info) structure.

## Remarks

## See also

[Adding Extensible Switch Destination Port Data to a Packet](https://learn.microsoft.com/windows-hardware/drivers/network/adding-extensible-switch-destination-port-data-to-a-packet)

[Cloning Packet Traffic](https://learn.microsoft.com/windows-hardware/drivers/network/cloning-or-duplicating-packet-traffic)

[Excluding Packet Delivery to Extensible Switch Destination Ports](https://learn.microsoft.com/windows-hardware/drivers/network/excluding-packet-delivery-to-extensible-switch-destination-ports)

[Forwarding Extensions](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-extensions)

[Forwarding Packets to Hyper-V Extensible Switch Ports](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-packets-to-hyper-v-extensible-switch-ports)

[Forwarding Packets to Physical Network Adapters](https://learn.microsoft.com/windows-hardware/drivers/network/forwarding-packets-to-physical-network-adapters)

[Modifying a Packet's Extensible Switch Source Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/modifying-a-packet-s-extensible-switch-source-port-data)

[Overview of the Hyper-V Extensible Switch](https://learn.microsoft.com/windows-hardware/drivers/network/overview-of-the-hyper-v-extensible-switch)

[Packet Management Guidelines for the Extensible Switch Data Path](https://learn.microsoft.com/windows-hardware/drivers/network/packet-management-guidelines-for-the-extensible-switch-data-path)

[Querying a Packet's Extensible Switch Source Port Data](https://learn.microsoft.com/windows-hardware/drivers/network/querying-a-packet-s-extensible-switch-source-port-data)

[**NDIS_SWITCH_FORWARDING_DETAIL_NET_BUFFER_LIST_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_switch_forwarding_detail_net_buffer_list_info)

[**NET_BUFFER_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)