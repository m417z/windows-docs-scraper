# NetRingGetPacketAtIndex function

## Description

The **NetRingGetPacketAtIndex** function retrieves a packet from a net ring.

## Parameters

### `Ring`

A pointer to a [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

### `Index`

The packet index, within the range **[0, Ring->NumberOfElements)**.

## Return value

Returns a pointer to the [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) at the specified index in the packet ring.

## Remarks

This function is a convenient wrapper around [**NetRingGetElementAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetelementatindex). Client drivers should call this function when working with a packet ring instead of calling **NetRingGetElementAtIndex** directly.

## See also

[**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)

[**NetRingGetElementAtIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/nf-ring-netringgetelementatindex)