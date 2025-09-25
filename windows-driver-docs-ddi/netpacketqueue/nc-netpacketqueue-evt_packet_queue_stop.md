# EVT_PACKET_QUEUE_STOP callback function

## Description

The *EvtPacketQueueStop* callback function is an optional callback that is implemented by the client driver to stop the data path for a packet queue.

## Parameters

### `PacketQueue` [_In_]

A handle to a packet queue.

## Prototype

```C++
//Declaration

EVT_PACKET_QUEUE_STOP EvtPacketQueueStop;

// Definition

VOID EvtPacketQueueStop
(
	NETPACKETQUEUE PacketQueue
)
{...}

```

## Remarks

This is an optional callback. Register this callback function in your *EVT_NET_ADAPTER_CREATE_TX(rxQueueContext)QUEUE* callback. Set the appropriate member of a [**NET_PACKET_QUEUE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/ns-netpacketqueue-_net_packet_queue_config) structure after you initialize the structure with [**NET_PACKET_QUEUE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nf-netpacketqueue-net_packet_queue_config_init), then call **NetTx(rxQueueContext)QueueCreate**.

This callback does not return a value and therefore should not fail, so this callback should be a light-weight function that executes quickly.

Client drivers will not receive calls to [*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance), [*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel), or [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) after *EvtPacketQueueStop* returns. In addition, *EvtPacketQueueStop* is called in the same execution context, or thread, as *EvtPacketQueueAdvance*, *EvtPacketQueueCancel*, and *EvtPacketQueueSetNotificationEnabled*, so client drivers do not need to synchronize between these callback functions for an individual queue instance.

For more info and a diagram showing the NetAdapterCx data path polling model, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[*EVT_NET_ADAPTER_CREATE_RXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue)

[*EVT_NET_ADAPTER_CREATE_TXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)

[**NetRxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netrxqueue/nf-netrxqueue-netrxqueuecreate)

[**NetTxQueueCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/nettxqueue/nf-nettxqueue-nettxqueuecreate)

[*EVT_PACKET_QUEUE_START*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_start)

[*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance)

[*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled)

[*EVT_PACKET_QUEUE_CANCEL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_cancel)