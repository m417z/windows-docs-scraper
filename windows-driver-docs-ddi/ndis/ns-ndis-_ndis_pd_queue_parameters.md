# _NDIS_PD_QUEUE_PARAMETERS structure

## Description

This structure is used to hold parameters for a transmit or receive queue when calling any of the queue routines.

## Members

### `Header`

The [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure for the [NDIS_PD_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_config) structure. Set the members of this structure as follows:

* **Type** = **NDIS_OBJECT_TYPE_DEFAULT**
* **Revision** = **NDIS_PD_QUEUE_PARAMETERS_REVISION_1**
* **Size** = **NDIS_SIZEOF_PD_QUEUE_PARAMETERS_REVISION_1**

### `Flags`

This member is reserved and must be set to 0 by the provider.

### `QueueType`

The type of the queue. For more information see, [NDIS_PD_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-ndis_pd_queue_type).

### `QueueSize`

The maximum amount of [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures this queue can hold and is always equal to a number of the form (2^k)-1 (63, 127, 255, 511, 1023, etc.). This lends itself to efficient circular index arithmetic.

### `ReceiveDataLength`

The minimum [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) data length.

### `Affinity`

The processor affinity is a hint to the provider for performance optimization. The platform will primarily be processing the queue on processors indicated by this mask. The provider must set this value to the processor core derived from the indirection table configured from [OID_GEN_RECEIVE_SCALE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-gen-receive-scale-parameters)

### `TrafficClassId`

### `MaximumPartialBufferCount`

For transmit queues, this is the maximum number of partial [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures that the client is allowed to chain together to form a single L2 packet. This value must be equal to the MaximumTxPartialBufferCount value in the [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure.

For receive queues, this is the maximum number of partial [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures that the provider is allowed to chain together to form a single large L2 packet with RSC. This must be less than or equal to the MaximumRxPartialBufferCount value in the [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure.

**Note** The client never posts [PD_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_pd_buffer) structures with the partial flag to the receive queue. The client is always required to post **PD_BUFFER** structures with at least MTU-size space, starting from the data start position. The provider performs chaining only in the case of RSC. Some providers may not be able to support RSC chaining, these providers set a value of 1 to the MaximumRxPartialBufferCount member in the [NDIS_PD_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_pd_capabilities) structure.

### `CounterHandle`

This is a handle to the transmit queue counter for transmit queues and a receive queue counter for receive queues.During queue creation, a client can optionally provide a counter handle. In this case and depending on the queue type, the provider must update the counter values as activity occurs on the queue. The client is responsible for closing the counter handle only after the queue is closed.

For queues that are not directly created by the client, such as RSS receive queues obtained using the [NdisPDOnRssReceiveQueues](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/)routine, the provider must always have an associated counter handle with the queue. That is, for a given set of RSS receive queues, the provider must have one dedicated receive queue counter for each receive queue.

## Remarks

This structure must be aligned on an 8-byte boundary.

## See also

[NDIS_PD_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ne-ndis-ndis_pd_queue_type)

[NdisPDAllocateQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_queue)