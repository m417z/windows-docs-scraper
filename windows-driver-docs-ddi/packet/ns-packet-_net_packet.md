# _NET_PACKET structure

## Description

Represents a single network packet.

## Members

### `FragmentIndex`

The index in the fragment ring of the first [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) structure in this packet's payload.

### `FragmentCount`

The number of [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) structures that belong to this packet.

### `Layout`

A [**NET_PACKET_LAYOUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet_layout) structure.

For transmit queues, if the host stack has enabled a task offload that uses a protocol header, specifies a read-only offset to each protocol field. For example, if TCP checksum offload is enabled, this member specifies the offset to the TCP header. Otherwise, this member is empty.

For receive queues, if the host stack has enabled a task offload that uses a protocol header, set the **Layer2Type**, **Layer3Type**, and **Layer4Type** flags. When there are no task offloads this member is empty.

### `Ignore`

For receive queues, the client sets this field to prevent the packet from being indicated to the host. For example, if the hardware encountered a DMA error while writing bytes into this the data buffer for this packet's fragments, the client can set this field to drop the partial packet.

For transmit queues, this field is read-only. If set, it indicates that the client should not transmit the packet.

### `Scratch`

A bit field value that the client may use for any purpose. When the **NET_PACKET** is reused, this value is reset to zero.

### `Reserved1`

Reserved. Client drivers must not read or write this value.

## Remarks

Each **NET_PACKET** structure represents a single network frame and contains basic metadata applicable to all packets, such as the framing layout. A **NET_PACKET** contains at least one [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) that describes the location in system memory where the packet data resides.

The **NET_PACKET** structure can be an element in a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring) structure.

## See also