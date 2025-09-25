# NET_EXTENSION_TYPE enumeration

## Description

The **NET_EXTENSION_TYPE** enumeration specifies the type of extension that a client driver is querying.

## Constants

### `NetExtensionTypePacket:1`

The extension is a [**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet) extension.

### `NetExtensionTypeFragment:2`

The extension is a [**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment) extension.

### `NetExtensionTypeBuffer`
Reserved for system use.

## Remarks

Client drivers pass this enumeration as a value to [**NET_EXTENSION_QUERY_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/nf-netadapterpacket-net_extension_query_init) to differentiate between packet extensions and fragment extension queries during packet queue creation.

## See also

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NET_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/packet/ns-packet-_net_packet)

[**NET_FRAGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fragment/ns-fragment-_net_fragment)

[**NET_EXTENSION_QUERY_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapterpacket/nf-netadapterpacket-net_extension_query_init)