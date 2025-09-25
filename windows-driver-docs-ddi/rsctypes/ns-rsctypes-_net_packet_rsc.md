# NET_PACKET_RSC structure

## Description

The **NET_PACKET_RSC** structure contains receive segment coalescence (RSC) information for a packet.

## Members

### `DUMMYUNIONNAME`

A union that contains the **TCP** and **UDP** members.

### `DUMMYUNIONNAME.TCP`

A structure that holds the TCP RSC information.

### `DUMMYUNIONNAME.TCP.CoalescedSegmentCount`

The number of TCP data segments that were coalesced.

### `DUMMYUNIONNAME.TCP.DuplicateAckCount`

The number of duplicate ACK messages.

### `DUMMYUNIONNAME.UDP`

A structure that holds the UDP RSC information.

### `DUMMYUNIONNAME.UDP.CoalescedSegmentCount`

The number of UDP data segments that were coalesced.

### `DUMMYUNIONNAME.UDP.CoalescedSegmentSize`

The size, in bytes, of the UDP data segments that were coalesced.

## Remarks

Client drivers can obtain this structure for a packet by calling [**NetExtensionGetPacketRsc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rsc/nf-rsc-netextensiongetpacketrsc).

## See also

[Receive Segment Coalescing (RSC) offload](https://learn.microsoft.com/windows-hardware/drivers/netcx/rsc-offload)

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)