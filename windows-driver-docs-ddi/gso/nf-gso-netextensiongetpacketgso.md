## Description

The **NetExtensionGetPacketGso** function retrieves [Generic Segmentation Offload (GSO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload) information for a packet.

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the GSO extension information for this packet queue.

### `Index`

The index in the packet ring for the target [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Return value

Returns a pointer to a [**NET_PACKET_GSO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gsotypes/ns-gsotypes-net_packet_gso) structure that holds the GSO information for this packet.

## Remarks

NIC client drivers typically query offsets for packet extensions during datapath queue creation, then store them in their queue context space so they don't have to query them too often. For an example of this, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues). Clients can retrieve the GSO offset from the queue context to pass to **NetExtensionGetPacketGso**.

This function is a wrapper function around [**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata).

## See also

[Generic Segmentation Offload (GSO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[**NET_PACKET_GSO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gsotypes/ns-gsotypes-net_packet_gso)

[**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata)