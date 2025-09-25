# _SELF_ID_MORE structure

## Description

The SELF_ID_MORE structure contains a raw packet one, two, or three self-ID packet. See the IEEE 1394 specification for details.

## Members

### `SID_Phys_ID`

Specifies the device node number. This member specifies bits 0-10 of the node address. This member contains bits 0-5 of byte 0 of the self ID packet.

### `SID_Packet_ID`

Must be PHY_PACKET_ID_SELF_ID. This member specifies bits 0-10 of the node address. This member contains bits 6-7 of byte 0 of the self ID packet.

### `SID_PortA`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 0-1 of byte 1 of the self ID packet.

### `SID_Reserved2`

Reserved. This member contains bits 2-3 of byte 1 of the self ID packet.

### `SID_Sequence`

Specifies the packet number in sequence (the first SELF_ID_MORE packet is packet zero). This member contains bits 4-5 of byte 1 of the self ID packet.

### `SID_One`

Always a 1. This member contains bit 6 of byte 1 of the self ID packet.

### `SID_PortE`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member specifies bits 0-1 of byte 2 of the self ID packet.

### `SID_PortD`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member specifies bits 2-3 of byte 2 of the self ID packet.

### `SID_PortC`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 4-5 of byte 2 of the self ID packet.

### `SID_PortB`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 6-7 of byte 2 of the self ID packet.

### `SID_More_Packets`

One if this packet will be followed by more SELF_ID_MORE packets, zero otherwise. This member contains bit 0 of byte 3 of the self ID packet.

### `SID_Reserved3`

Reserved. This member contains bit 1 of byte 3 of the self ID packet.

### `SID_PortH`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 2-3 of byte 3 of the self ID packet.

### `SID_PortG`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 4-5 of byte 3 of the self ID packet.

### `SID_PortF`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

This member contains bits 6-7 of byte 3 of the self ID packet.

## Remarks

This structure corresponds to self ID packet 1, as described in the *P1394a* specification. Note that type 2 self ID packets are identical to type 1 packets, except that the last five fields are replaced by a reserved area. The SELF_ID_MORE structure can be used to access all of the significant information in both type 1 and type 2 self ID packets.

## See also

[TOPOLOGY_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_topology_map)