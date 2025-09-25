# _NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE enumeration

## Description

The **NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE** enumeration identifies the current queue state of a receive
queue.

## Constants

### `NdisReceiveQueueOperationalStateUndefined`

The receive queue is in the
Undefined state. The queue is not allocated.

### `NdisReceiveQueueOperationalStateRunning`

The receive queue is in the
Running state. The queue was allocated successfully, there is at least one filter set on the
queue, and the miniport driver has completed, or will complete, the
[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete) OID request with a success status.

### `NdisReceiveQueueOperationalStatePaused`

The receive queue is in the
Paused state. The queue was allocated successfully with the
[OID_RECEIVE_FILTER_ALLOCATE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-allocate-queue) OID. There are no filters set on the queue.

### `NdisReceiveQueueOperationalStateDmaStopped`

The DMA operations on the queue are stopped because the queue is being freed, and the queue is in
the
DMA Stopped state. The queue enters the
DMA Stopped state when the miniport driver receives an
[OID_RECEIVE_FILTER_FREE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-free-queue) OID request, stops the DMA operations for the queue, and issues an
[NDIS_STATUS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state) status indication.

### `NdisReceiveQueueOperationalStateMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The **NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE** enumeration is used in the
[NDIS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state) and
[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info) structures.

## See also

[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info)

[NDIS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state)

[NDIS_STATUS_RECEIVE_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_receive_queue_state)

[OID_RECEIVE_FILTER_ALLOCATE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-allocate-queue)

[OID_RECEIVE_FILTER_FREE_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-free-queue)

[OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-receive-filter-queue-allocation-complete)