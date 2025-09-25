# NetExtensionGetData function

## Description

The **NetExtensionGetData** function retrieves packet extension data for a net packet.

## Parameters

### `Extension`

A pointer to a [**NET_EXTENSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/extension/ns-extension-_net_extension) structure that describes the requested extension information for this packet queue.

### `Index`

The index in the packet ring for the target [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet).

## Return value

Returns a pointer to the structure that holds the extension information for this packet.

## Remarks

Client drivers should not call this function directly. Instead, they should call the appropriate wrapper function for the type of extension they are getting:

- For checksum offload information, the client driver calls [**NetExtensionGetPacketChecksum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksum/nf-checksum-netextensiongetpacketchecksum).
- For Generic Segmentation Offload (GSO) information, the client driver calls [**NetExtensionGetPacketLso**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gso/nf-gso-netextensiongetpacketgso).
- For Receive Segment Coalescence (RSC) offload information, the client driver calls [**NetExtensionGetPacketRsc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rsc/nf-rsc-netextensiongetpacketrsc).

## -see-aextension

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[Transmit and receive queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/transmit-and-receive-queues)

[**NetExtensionGetPacketChecksum**](https://learn.microsoft.com/windows-hardware/drivers/ddi/checksum/nf-checksum-netextensiongetpacketchecksum)

[**NetExtensionGetPacketGso**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gso/nf-gso-netextensiongetpacketgso)

[**NetExtensionGetPacketRsc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/rsc/nf-rsc-netextensiongetpacketrsc)