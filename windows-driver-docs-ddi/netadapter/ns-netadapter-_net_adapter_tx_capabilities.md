# _NET_ADAPTER_TX_CAPABILITIES structure

## Description

The **NET_ADAPTER_TX_CAPABILITIES** structure describes the transmit capabilities of a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `MappingRequirement`

A [**NET_MEMORY_MAPPING_REQUIREMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_memory_mapping_requirement) value that specifies how the operating system should map transmit data buffers.

UMDF drivers must set **MappingRequirement** to **NetMemoryMappingRequirementNone**.

### `PayloadBackfill`

The amount of space, in bytes, reserved for the client driver before the start of each [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)'s payload.

### `MaximumNumberOfFragments`

The maximum number of fragments per packet that the adapter can handle, or `((SIZE_T) - 1)` if there is no limit.

### `FragmentBufferAlignment`

The minimum alignment for packet fragments. This member must be a power of 2.

### `FragmentRingNumberOfElementsHint`

A hint indicating how many elements the adapter wants for each transmit queue's [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) ring buffer. This member must be a power of 2.

### `MaximumNumberOfQueues`

The maximum number of transmit queues that the adapter supports.

### `DmaCapabilities`

A pointer to a driver-allocated and initialized [**NET_DMA_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure that describes the adapter's DMA capabilities on the transmit path. This member is ignored by NetAdapterCx if **MappingRequirement** is not set to **NetMemoryMappingRequirementDmaMapped**.

UMDF NetAdapterCX doesn't support **DmaCapabilities**. UMDF drivers must set this member to **NULL**.

## Remarks

Call one of the NET_ADAPTER_TX_CAPABILITIES_INIT_*XXX* functions to initialize this structure. For more info about each initialization function, see the links in the See Also section.

An initialized **NET_ADAPTER_TX_CAPABILITIES** structure is passed as a parameter to [**NetAdapterSetDatapathCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities).

## See also

[**NET_ADAPTER_TX_CAPABILITIES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init)

[**NET_ADAPTER_TX_CAPABILITIES_INIT_FOR_DMA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_tx_capabilities_init_for_dma)