# _NET_ADAPTER_RX_CAPABILITIES structure

## Description

The **NET_ADAPTER_RX_CAPABILITIES** structure describes the receive capabilities of a net adapter.

## Members

### `Size`

The size of this structure, in bytes.

### `AllocationMode`

A [**NET_RX_FRAGMENT_BUFFER_ALLOCATION_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_rx_fragment_buffer_allocation_mode) value that specifies how the operating system should allocate receive buffers.

UMDF drivers must set this value to **NetRxFragmentBufferAllocationModeSystem**.

### `AttachmentMode`

A [**NET_RX_FRAGMENT_BUFFER_ATTACHMENT_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_rx_fragment_buffer_attachment_mode) value that specifies how the operating system should pre-attach receive buffers.

UMDF drivers must set this value to **NetRxFragmentBufferAttachmentModeSystem**.

### `FragmentRingNumberOfElementsHint`

A hint indicating how many elements the adapter wants for each receive queue's ring buffer of [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)s. This member must be a power of 2.

### `MaximumFrameSize`

The maximum frame size, in bytes, that the adapter can receive. This value should include the maximum transmission unit (MTU) size that your hardware supports for an IP packet, plus additional space your driver might need for packet metadata. For more information, see the receive example in the Remarks section of [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance).

### `MaximumNumberOfQueues`

The maximum number of receive queues that the adapter supports.

### `DUMMYUNIONNAME`

A union that contains the following members:

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

A struct that contains the following member:

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.EvtAdapterReturnRxBuffer`

A pointer to the driver's [*EVT_NET_ADAPTER_RETURN_RX_BUFFER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_return_rx_buffer) callback function. This member is required if the **AllocationMode** member is set to **NetRxFragmentBufferAllocationModeDriver** for the operating system to invoke once the system is finished with the receive buffer.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2`

A struct that contains the following members:

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.MappingRequirement`

A [**NET_MEMORY_MAPPING_REQUIREMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ne-netadapter-_net_memory_mapping_requirement) value that specifies how the operating system should map receive data buffers.

UMDF drivers must set **MappingRequirement** to **NetMemoryMappingRequirementNone**.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.FragmentBufferAlignment`

The minimum alignment for packet fragments. This member must be a power of 2.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.DmaCapabilities`

A pointer to a driver-allocated and initialized [**NET_ADAPTER_DMA_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_dma_capabilities) structure that describes the adapter's DMA capabilities on the receive path. This member is ignored by NetAdapterCx if **MappingRequirement** is not set to **NetMemoryMappingRequirementDmaMapped**.

UMDF NetAdapterCX doesn't support **DmaCapabilities**. UMDF drivers must set this member to **NULL**.

## Remarks

Call one of the NET_ADAPTER_RX_CAPABILITIES_INIT_*XXX* functions to initialize this structure. For more info about each initialization function, see the links in the See Also section. An initialized **NET_ADAPTER_RX_CAPABILITIES** structure is passed as a parameter to [**NetAdapterSetDatapathCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities).

Typically, a client driver either performs both allocation and attachment itself or specifies that the operating system perform both. In most cases, we recommend that the operating system allocates and attaches receive buffers.

If the client does specify driver-allocated and attached receive buffers, it must supply both a custom return context structure in the **RxBufferReturnContext** member of each [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) during buffer allocation, as well as an *EVT_NET_ADAPTER_RETURN_RX_BUFFER* callback function in this **NET_ADAPTER_RX_CAPABILITIES** structure for the operating system to invoke once it has finished with the buffer.

## See also

[**NET_ADAPTER_RX_CAPABILITIES_INIT_DRIVER_MANAGED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_driver_managed)

[**NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed)

[**NET_ADAPTER_RX_CAPABILITIES_INIT_SYSTEM_MANAGED_DMA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_rx_capabilities_init_system_managed_dma)

[**NetAdapterSetDatapathCapabilities**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetdatapathcapabilities)