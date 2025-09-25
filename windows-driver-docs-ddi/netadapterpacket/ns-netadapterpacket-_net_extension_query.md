# NET_EXTENSION_QUERY structure

## Description

The **NET_EXTENSION_QUERY** structure represents a query for a packet or fragment extension.

## Members

### `Size`

The size of this structure, in bytes.

### `Name`

The name of the extension to be queried.

### `Version`

The version of the extension to be queried.

### `Type`

A [**NET_EXTENSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ne-extension-_net_extension_type) value that specifies the type of extension being queried.

## Remarks

Call [**NET_EXTENSION_QUERY_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/nf-netadapterpacket-net_extension_query_init) to initialize this structure.

For more info about extensions, see [Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions).

For a code example of querying extension offsets, see [Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues).

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[**NET_EXTENSION_QUERY_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/nf-netadapterpacket-net_extension_query_init)

[**NET_EXTENSION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ne-extension-_net_extension_type)