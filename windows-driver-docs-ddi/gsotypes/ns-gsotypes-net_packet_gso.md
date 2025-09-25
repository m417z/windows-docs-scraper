## Description

The **NET_PACKET_GSO** structure contains [Generic Segmentation Offload (GSO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload) information for a packet.

## Members

### `DUMMYUNIONNAME`

A union that contains the TCP and UDP member.

### `DUMMYUNIONNAME.TCP`

A structure that holds the TCP GSO information.

### `DUMMYUNIONNAME.TCP.Mss`

The maximum segment size (MSS) for TCP segments.

### `DUMMYUNIONNAME.TCP.Reserved0`

Reserved for system use. Clients must not read or write this member.

### `DUMMYUNIONNAME.UDP`

A structure that holds the UDP GSO information.

### `DUMMYUNIONNAME.UDP.Mss`

The MSS for UDP segments.

### `DUMMYUNIONNAME.UDP.Reserved0`

Reserved for system use. Clients must not read or write this member.

## Remarks

Client drivers can obtain this structure for a packet by calling [**NetExtensionGetPacketGso**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gso/nf-gso-netextensiongetpacketgso).

## See also

[Generic Segmentation Offload (GSO)](https://learn.microsoft.com/windows-hardware/drivers/netcx/gso-offload)

[Packet descriptors and extensions](https://learn.microsoft.com/windows-hardware/drivers/netcx/packet-descriptors-and-extensions)

[**NetExtensionGetPacketGso**](https://learn.microsoft.com/windows-hardware/drivers/ddi/gso/nf-gso-netextensiongetpacketgso)