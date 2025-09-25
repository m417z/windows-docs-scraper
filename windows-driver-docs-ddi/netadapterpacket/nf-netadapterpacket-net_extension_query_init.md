# NET_EXTENSION_QUERY_INIT function

## Description

The **NET_EXTENSION_QUERY_INIT** function initializes a [**NET_EXTENSION_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/ns-netadapterpacket-_net_extension_query) structure.

## Parameters

### `Extension` [_Out_]

A pointer to a driver-allocated [**NET_EXTENSION_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/ns-netadapterpacket-_net_extension_query) structure.

### `Name` [_In_]

The name of the extension to be queried.

### `Version` [_In_]

The version of the extension to be queried.

### `Type` [_In_]

A [**NET_EXTENSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ne-extension-_net_extension_type) value that specifies the type of extension being queried.

## Remarks

After calling this function, pass the initialized **NET_EXTENSION_QUERY** structure to **NetTx(Rx)QueueGetExtension** to get the offset to that extension in the packet or fragment descriptor.

To prevent re-querying extension offsets too often, call this function and **NetTx(Rx)QueueGetExtension** from the *EvtNetAdapterCreateTx(Rx)Queue* callback function after calling **NetTx(Rx)QueueCreate**, then store the offset in a queue context space.

For more info about extensions, see [Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions).

For a code example of querying extension offsets, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[**NET_EXTENSION_QUERY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/ns-netadapterpacket-_net_extension_query)

[**NET_EXTENSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ne-extension-_net_extension_type)