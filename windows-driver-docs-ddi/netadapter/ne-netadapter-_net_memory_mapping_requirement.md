# _NET_MEMORY_MAPPING_REQUIREMENT enumeration

## Description

The **NET_MEMORY_MAPPING_REQUIREMENT** enumeration identifies the memory mapping requirement that a net adapter can specify for its receive and transmit buffers.

## Constants

### `NetMemoryMappingRequirementNone:0`

The adapter does not require memory mapping.

### `NetMemoryMappingRequirementDmaMapped:1`

The adapter requires DMA mapping for mapping receive or transmit buffers.

## Remarks

## See also

[NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities)

[NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities)