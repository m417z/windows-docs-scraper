# _NET_RING structure

## Description

Specifies a buffer comprised of one or more [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) or [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) structures.

## Members

### `OSReserved1`

Reserved. Client drivers must not read or write to this value.

### `ElementStride`

A read-only byte offset from the start of one element to the start of the next. Use `((BYTE*)p + ElementStride)` to obtain the address of the next element.

### `NumberOfElements`

A read-only value that indicates the number of packets in the ring buffer, which is always a power of two, and greater than one.

### `ElementIndexMask`

A read-only UINT32 mask that can be used to efficiently clamp an index to **[0, NumberOfElements)**. The client can use this value to calculate an index that wraps around the ring buffer. Use the identity `(x % NumberofElements) == (x & ElementIndexMask)`.

### `EndIndex`

Specifies the read-only index of the last element that is owned by the client driver in the inclusive range [0, **NumberOfElements** - 1].

### `DUMMYUNIONNAME`

A union that contains the **OSReserved0** and **OSReserved2** members.

### `DUMMYUNIONNAME.OSReserved0`

Reserved. Client drivers must not read or write to this value.

### `DUMMYUNIONNAME.OSReserved2`

Reserved. Client drivers must not read or write to this value.

### `BeginIndex`

Specifies the index of the first element owned by the client driver in the inclusive range [0, **NumberOfElements** - 1].

### `NextIndex`

Specifies the index of the next element that needs processing. For optional use by the client driver.

### `Scratch`

A pointer to a buffer that the client driver may use for any purpose.

### `Buffer`

A byte array that contains the elements in the net ring. Typically, a client driver calls [**NetRingGetPacketAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetpacketatindex) or [**NetRingGetFragmentAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetfragmentatindex) to access the elements of the ring buffer.

## Remarks

The **NET_RING** structure is a generic ring buffer, optimized for efficient access from a single thread. A **NET_RING** contains [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) or [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) elements.

For more info about packet and fragment ring buffers, see [Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions#storage-of-packet-descriptors).

For more info about using net rings, see [Introduction to net rings](https://learn.microsoft.com/windows-hardware/drivers/netcx/introduction-to-net-rings).

## See also