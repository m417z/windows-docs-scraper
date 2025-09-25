# EVT_PACKET_QUEUE_START callback function

## Description

The *EvtPacketQueueStart* callback function is an optional callback that is implemented by the client driver to start the data path for a packet queue.

## Parameters

### `PacketQueue` [_In_]

A handle to a packet queue.

## Prototype

```C++
//Declaration

EVT_PACKET_QUEUE_START EvtPacketQueueStart;

// Definition

VOID EvtPacketQueueStart
(
	NETPACKETQUEUE PacketQueue
)
{...}

```

## Remarks

This is an optional callback. Register this callback function in your *EVT_NET_ADAPTER_CREATE_TX(RX)QUEUE* callback. Set the appropriate member of a [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure after you initialize the structure with [**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init), then call **NetTx(Rx)QueueCreate**.

In this callback, a client driver typically configures information that its hardware needs for packet transmission or reception. Because this callback does not return a value and therefore should not fail, client drivers should perform actions such as resource allocation during queue creation. Therefore, this callback should be a light-weight function that executes quickly.

Client drivers will not receive calls to [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance), [*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel), or [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) until after *EvtPacketQueueStart* returns. In addition, *EvtPacketQueueStart* is called in the same execution context, or thread, as *EvtPacketQueueAdvance*, *EvtPacketQueueCancel*, and *EvtPacketQueueSetNotificationEnabled*, so client drivers do not need to synchronize between these callback functions for an individual queue instance.

When a queue starts, NetAdapterCx guarantees that **BeginIndex** == **NextIndex** == **0** for all of this queue's ring buffers. After start, the framework does not read or write **NextIndex** for packet ring buffers, so client drivers can either use it as needed or choose not to use it at all. **BeginIndex** is read by the framework but is not modified outside of *EvtPacketQueueStart*.

For more info and a diagram showing the NetAdapterCx data path polling model, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[*EVT_NET_ADAPTER_CREATE_RXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue)

[*EVT_NET_ADAPTER_CREATE_TXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)

[**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate)

[**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate)

[*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance)

[*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel)

[*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled)

[*EVT_PACKET_QUEUE_STOP*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_stop)