# NetTxQueueGetExtension function

## Description

The **NetTxQueueGetExtension** function retrieves a packet extension for all packets in a transmit (Tx) queue.

## Parameters

### `PacketQueue` [_In_]

The transmit queue object.

### `Query` [_In_]

A pointer to a driver-allocated and initialized [**NET_EXTENSION_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/ns-netadapterpacket-_net_extension_query) structure that contains information about the desired packet extension.

### `Extension` [_Out_]

A handle to a driver-allocated [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that receives the packet extension.

## Remarks

Client drivers typically call this function from their *[EvtNetAdapterCreateTxQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue)* callback function after queue creation. To prevent frequent extension queries, store the extension returned by this function in your queue context space.

For a code example of creating a transmit queue, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)