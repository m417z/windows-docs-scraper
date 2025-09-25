## Description

The **PKTMON_EVT_STREAM_METADATA** structure contains metadata information used for event streaming.

## Members

### `PktGroupId`

Group Id for packets belonging to the same processor.

### `PktCount`

The number of packets.

### `AppearanceCount`

Packet Count belonging to the same Net Buffer List.

### `DirectionName`

Enum value of [PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction). Specifies the direction for which the packet was reported.

### `PacketType`

Packet Payload type as [PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type).

### `ComponentId`

ID of the component that reported the packet.

### `EdgeId`

Edge ID of the component boundary from which packet was reported. An edge represents a pair of entry and exit points.

### `FilterId`

The filter identifier.

### `DropReason`

Packet drop reason code, defined in the [PKTMON_DROP_REASON](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream#pktmon_drop_reason) enum.

### `DropLocation`

Packet drop location defined in the [PKTMON_DROP_LOCATION](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream#pktmon_drop_location) enum.

### `ProcNum`

Processor number when the packet was reported.

### `TimeStamp`

Timestamp when the packet was reported. This is retrieved using [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime~r1).

## Remarks

For more information, see the [PacketMonitorCreateRealtimeStream](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream) function.

## See also

- [PKTMON_DIRECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_direction)
- [PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)
- [PKTMON_DROP_REASON](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream#pktmon_drop_reason)
- [PKTMON_DROP_LOCATION](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream#pktmon_drop_location)
- [KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime~r1)
- [PacketMonitorCreateRealtimeStream](https://learn.microsoft.com/windows/win32/pktmon/packetmonitor/nf-packetmonitor-packetmonitorcreaterealtimestream)