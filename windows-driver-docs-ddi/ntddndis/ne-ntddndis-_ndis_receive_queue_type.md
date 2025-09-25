# _NDIS_RECEIVE_QUEUE_TYPE enumeration

## Description

The **NDIS_RECEIVE_QUEUE_TYPE** enumeration identifies the type of a receive queue.

## Constants

### `NdisReceiveQueueTypeUnspecified`

The receive queue type is not specified.

### `NdisReceiveQueueTypeVMQueue`

This value specifies a virtual machine (VM) receive queue.

### `NdisReceiveQueueTypeMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_RECEIVE_QUEUE_TYPE enumeration is used in the
**QueueType** member of the
[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters) and
[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info) structures.

## See also

[NDIS_RECEIVE_QUEUE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_info)

[NDIS_RECEIVE_QUEUE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_queue_parameters)