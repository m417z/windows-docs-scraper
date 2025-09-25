# _NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE enumeration

## Description

The **NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE** enumeration identifies how the operating system should allocate [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffers for a net adapter client driver's receive queues.

## Constants

### `NetRxFragmentBufferAllocationModeSystem:0`

The operating system allocates [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffers on behalf of the client driver.

### `NetRxFragmentBufferAllocationModeDriver:1`

The operating system never allocates [NET_FRAGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) receive buffers. The client driver is responsible for buffer allocation.

## Remarks

This enumeration is a value of the [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure. Together with [NET_RX_FRAGMENT_BUFFER_ATTACHMENT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_rx_fragment_buffer_attachment_mode), it specifies how a net adapter client driver would like to configure its receive queue fragment buffers. For more information, see [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities).

## See also

[NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)