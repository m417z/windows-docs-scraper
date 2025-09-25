# EVT_PACKET_QUEUE_CANCEL callback function

## Description

The *EvtPacketQueueCancel* callback function is implemented by the client driver to handle operations that must be performed before a packet queue is deleted.

## Parameters

### `PacketQueue` [_In_]

A handle to a packet queue.

## Prototype

```C++
//Declaration

EVT_PACKET_QUEUE_CANCEL EvtPacketQueueCancel;

// Definition

VOID EvtPacketQueueCancel
(
	NETPACKETQUEUE PacketQueue
)
{...}

```

## Remarks

Register this callback function in your *EVT_NET_ADAPTER_CREATE_TX(RX)QUEUE* callback. Set the appropriate member of a [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure when you are initializing the structure with [**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init), then call **NetTx(Rx)QueueCreate**.

NetAdapterCx serializes this callback function along with the packet queue's [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance) and [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance) callback functions.

For more info and a diagram showing the NetAdapterCx data path polling model, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[*EVT_NET_ADAPTER_CREATE_RXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue)

[*EVT_NET_ADAPTER_CREATE_TXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)

[**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate)

[**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate)

[*EVT_PACKET_QUEUE_START*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_start)

[*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance)

[*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled)

[*EVT_PACKET_QUEUE_STOP*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_stop)