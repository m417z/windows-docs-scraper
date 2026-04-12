## Description

The **PKTMON_BUFFER_TYPE** enumeration defines the types of packet buffers that can be monitored by the Packet Monitor infrastructure. This enumeration specifies the format in which packet data is provided to the monitoring system.

## Constants

### `PktMonBuffer_NblChain`

Indicates that the packet buffer is a chain of NET_BUFFER_LIST structures. This is used for monitoring multiple linked network buffers.

### `PktMonBuffer_NblSingle`

Indicates that the packet buffer is a single NET_BUFFER_LIST structure. This is the most common buffer type for monitoring individual network packets.

### `PktMonBuffer_Wsk_Buf`

Indicates that the packet buffer is a Winsock Kernel (WSK) buffer. This buffer type is used for monitoring socket-level packet data.

### `PktMonBuffer_None`

Indicates that no packet buffer is provided. This is used when only packet header information is being logged without the actual packet data.

## Remarks

## See also

- [PKTMON_PACKET_LOG_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_log_in)
- [PktMonClntNblLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbllog)
- [PktMonClntNblDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbldrop)