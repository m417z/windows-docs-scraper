# NetPacketGetExtension function

## Description

The **NetPacketGetExtension** function retrieves information stored in one of a packet's extensions.

## Parameters

### `packet`

A pointer to a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) structure.

### `offset`

The offset, in bytes, to the desired [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) from the beginning of the packet's descriptor.

## Return value

Returns a pointer to a structure at the given extension offset that represents packet extension information.

## Remarks

NIC client drivers typically query offsets for packet extensions during datapath queue creation, then store them in their queue context space so they don't have to query them too often. For an example of this, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues). These offsets are then passed to **NetPacketGetExtension** to retrieve data for each packet extension.

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)