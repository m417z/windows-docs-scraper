# _NET_RX_FRAGMENT_BUFFER_ATTACHMENT_MODE enumeration

## Description

The **NET_RX_FRAGMENT_BUFFER_ATTACHMENT_MODE** enumeration identifies how the operating system should pre-attach [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) buffers to [NET_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)s for a net adapter client driver's receive queues.

## Constants

### `NetRxFragmentBufferAttachmentModeSystem:0`

The operating system attaches receive [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)s to [NET_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)s automatically. This value is valid **only** when receive fragment buffer allocation, identified by the [NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_rx_fragment_buffer_allocation_mode) enumeration, is also set to **NetRxFragmentBufferAllocationModeSystem**.

### `NetRxFragmentBufferAttachmentModeDriver:1`

The client driver is responsible for attaching [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffers to [NET_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)s.

## Remarks

This enumeration is a value of the [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure. Together with [NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_rx_fragment_buffer_allocation_mode), it specifies how a net adapter client driver would like to configure its receive queue fragment buffers. For more information, see [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities).

## See also