# _NET_FRAGMENT structure

## Description

Represents one contiguous buffer in memory.

## Members

### `ValidLength`

Contains the length of packet payload. This value is less than or equal to the value of **Capacity**.

For transmit queues, this value is read-only.

### `Capacity`

Contains the total length of the packet buffer.

For transmit queues, this value is read-only.

### `Offset`

Contains the offset from the start of the **VirtualAddress** and **DmaLogicalAddress** to the start of the valid packet payload. This value is less than or equal to the value of **Capacity**.

To obtain the virtual address for this fragment, call [**NetExtensionGetFragmentVirtualAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/virtualaddress/nf-virtualaddress-netextensiongetfragmentvirtualaddress).

To obtain the DMA logical address for this fragment, call [**NetExtensionGetFragmentLogicalAddress**](https://learn.microsoft.com/windows-hardware/drivers/ddi/logicaladdress/nf-logicaladdress-netextensiongetfragmentlogicaladdress).

For transmit queues, this value is read-only.

### `Scratch`

A bit field value that the client may use for any purpose. When the [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) to which this fragment belongs is reused, this value is reset to zero.

### `OsReserved_Bounced`

Reserved. Client drivers must not read or write to this value.

## Remarks

A single [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) structure contains references to one or more **NET_FRAGMENT** structures.

While each fragment is a virtually contiguous buffer of memory, a packet that contains more than one fragment is virtually discontiguous.

## See also