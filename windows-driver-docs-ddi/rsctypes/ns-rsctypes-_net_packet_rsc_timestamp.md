# NET_PACKET_RSC_TIMESTAMP structure

## Description

The **NET_PACKET_RSC_TIMESTAMP** structure contains receive segment coalescence (RSC) timestamp information for a packet.

## Members

### `DUMMYUNIONNAME`

A union that contains the **TCP** member.

### `DUMMYUNIONNAME.TCP`

A structure that holds the TCP RSC timestamp information.

### `DUMMYUNIONNAME.TCP.RscTcpTimestampDelta`

The absolute delta between the earliest and the latest TCP timestamp value seen in the sequence of coalesced segments comprising the Single Coalesced Unit (SCU).

## Remarks

Client drivers can obtain this structure for a packet by calling [**NetExtensionGetPacketRscTimeStamp**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rsc/nf-rsc-netextensiongetpacketrsctimestamp).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)