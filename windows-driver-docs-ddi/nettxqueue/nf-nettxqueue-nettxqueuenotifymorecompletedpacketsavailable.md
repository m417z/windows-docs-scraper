# NetTxQueueNotifyMoreCompletedPacketsAvailable function

## Description

The client driver calls **NetTxQueueNotifyMoreCompletedPacketsAvailable** to resume queue operations after NetAdapterCx calls the client's [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) event callback routine.

## Parameters

### `PacketQueue` [_In_]

A handle to a net transmit queue.

## Remarks

This function should only be called when polling is disabled.

After NetAdapterCx calls a client driver's [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) event callback routine with *NotificationEnabled* set to **TRUE**, the client enables the queue's hardware interrupt. When the device generates a hardware interrupt, the client typically calls **NetTxQueueNotifyMoreCompletedPacketsAvailable** from its *[EVT_WDF_INTERRUPT_DPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function, after it completes a pending [NET_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) in the transmit queue's [**NET_RING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ring/ns-ring-_net_ring).

The client should only call **NetTxQueueNotifyMoreCompletedPacketsAvailable** once per enabling of the notification. If the most recent call to [*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled) has *NotificationEnabled* set to **FALSE**, the client should avoid invoking **NetTxQueueNotifyMoreCompletedPacketsAvailable**. Because NetAdapterCx invokes *EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED* repeatedly, the client may miss a few cases and call **NetTxQueueNotifyMoreCompletedPacketsAvailable** when *NotificationEnabled* is set to **FALSE**. In these cases, the call will be a no-op.

## See also

[*EVT_PACKET_QUEUE_ADVANCE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_advance)

[*EVT_PACKET_QUEUE_SET_NOTIFICATION_ENABLED*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_set_notification_enabled)