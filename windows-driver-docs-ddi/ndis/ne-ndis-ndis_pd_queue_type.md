# NDIS_PD_QUEUE_TYPE enumeration

## Description

The **NDIS_PD_QUEUE_TYPE** enumeration defines types of PacketDirect Provider Interface (PDPI) queues. Its enumeration values are used in the **QueueType** member of the [NDIS_PD_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue_parameters) structure.

## Constants

### `PDQueueTypeUnknown`

The queue type is not known.

### `PDQueueTypeReceive`

The queue is a receive queue.

### `PDQueueTypeTransmit`

The queue is a transmit queue.

### `PDQueueTypeMax`

The maximum value for this enumeration. This value might change in future versions of NDIS header files and binaries.

## See also

[NDIS_PD_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_queue_parameters)

[NdisPDAllocateQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_pd_allocate_queue)