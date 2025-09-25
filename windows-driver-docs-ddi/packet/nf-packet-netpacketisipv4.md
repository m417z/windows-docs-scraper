# NetPacketIsIpv4 function

## Description

The **NetPacketIsIpv4** function determines if a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) is an IPv4 packet.

>[!WARNING]
> This function is reserved for system use. Do not call this function from your code.

## Parameters

### `packet`

A pointer to a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) structure.

## Return value

Returns **TRUE** if the packet is an IPv4 packet; false otherwise.

## Remarks

## See also