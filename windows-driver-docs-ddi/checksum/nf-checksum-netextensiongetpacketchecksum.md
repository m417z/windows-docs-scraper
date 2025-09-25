# NetExtensionGetPacketChecksum function

## Description

The **NetExtensionGetPacketChecksum** function retrieves checksum information for a packet.

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the checksum extension information for this packet queue.

### `Index`

The index in the packet ring for the target [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Return value

Returns a pointer to a [**NET_PACKET_CHECKSUM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksumtypes/ns-checksumtypes-_net_packet_checksum) structure that holds the checksum information for this packet.

## Remarks

NIC client drivers typically query offsets for packet extensions during datapath queue creation, then store them in their queue context space so they don't have to query them too often. For an example of this, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues). Clients can retrieve the checksum offset from the queue context to pass to **NetExtensionGetPacketChecksum**.

This function is a wrapper function around [**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NetExtensionGetData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/nf-extension-netextensiongetdata)