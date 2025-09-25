## Description

The **WifiTxQueueGetDemuxWmmInfo** function gets the priority that the WiFiCx framework will use for this queue.

## Parameters

### `Queue`

[_In_] A handle to this packet queue.

## Return value

Returns the queue priority.

## Remarks

The client driver should query the queue priority from [*EvtPacketQueueStart*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netpacketqueue/nc-netpacketqueue-evt_packet_queue_start).

For more information, see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)