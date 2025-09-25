# NET_PACKET_QUEUE_CONFIG_INIT function

## Description

The **NET_PACKET_QUEUE_CONFIG_INIT** function initializes a [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure.

## Parameters

### `Config` [_Out_]

A pointer to the driver-allocated [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure to initialize.

### `EvtAdvance` [_In_]

A pointer to the client driver's implementation of the [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance) callback function for this packet queue.

### `EvtSetNotificationEnabled` [_In_]

A pointer to the client driver's implementation of the [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance) callback function for this packet queue.

### `EvtCancel` [_In_]

A pointer to the client driver's implementation of the [*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel) callback function for this packet queue.

## Remarks

Client drivers must call this function to initialize a [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure before calling [**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate) or [**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate) to create a packet queue.

## See also

[**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config)

[**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate)

[**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate)