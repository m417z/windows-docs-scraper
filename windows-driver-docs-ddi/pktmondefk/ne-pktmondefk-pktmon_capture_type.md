## Description

The **PKTMON_CAPTURE_TYPE** enum specifies the type of packets to capture during packet monitoring. This enumeration is used when starting packet monitoring to control whether to capture all packets, only successfully flowing packets, only dropped packets, or no packets at all.

The capture type is specified when starting packet monitoring and determines which packets are reported by the packet monitor. For a packet monitoring session, the capture type controls whether flow events and drop events are enabled for the monitored components.

## Constants

### `PktMonCapture_All`

Capture all packets. Both flow packets and drop packets will be captured.

### `PktMonCapture_Flow`

Capture flow packets only. Only packets that are successfully flowing through the network stack will be captured.

### `PktMonCapture_Drop`

Capture drop packets only. Only packets that are dropped by the network stack will be captured.

### `PktMonCapture_None`

Capture no packets. Packet capturing is disabled.

## Remarks

## See also

- [PktMonClntNblLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbllog)
- [PktMonClntNblDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-PktMonClntNblDrop)
- [PktMonClntComponentRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-PktMonClntComponentRegister)