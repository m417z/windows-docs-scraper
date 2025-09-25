# _NET_PACKET_QUEUE_CONFIG structure

## Description

The **NET_PACKET_QUEUE_CONFIG** structure describes the configuration options for a NetAdapterCx client driver's packet queue.

## Members

### `Size`

The size of this structure, in bytes.

### `EvtStart`

A pointer to the client driver's [*EVT_PACKET_QUEUE_START*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_start) event callback function for this packet queue. This callback function is required.

### `EvtStop`

A pointer to the client driver's [*EVT_PACKET_QUEUE_STOP*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_stop) event callback function for this packet queue. This callback function is required.

### `EvtAdvance`

A pointer to the client driver's [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance) event callback function for this packet queue. This callback function is required.

### `EvtSetNotificationEnabled`

A pointer to the client driver's [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) event callback function for this packet queue. This callback function is required.

### `EvtCancel`

A pointer to the client driver's [*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel) event callback function for this packet queue. This callback function is required.

### `ExecutionContext`

A NETEXECUTIONCONTEXT object.

## Remarks

Call [**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init) to initialize this structure.

The **NET_PACKET_QUEUE_CONFIG** structure is an input parameter to [**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate) and [**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate). The client must use [**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init) to initialize this structure before calling **NetTx(Rx)QueueCreate**.

## See also

[**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init)

[**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate)

[**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate)