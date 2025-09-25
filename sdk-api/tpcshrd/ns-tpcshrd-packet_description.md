# PACKET_DESCRIPTION structure

## Description

Describes the content of the packet for a particular tablet recognizer context.

Do not use this structure to access the data contained in a packet. This structure describes the content of the packet.

## Members

### `cbPacketSize`

The size, in bytes, of the packet data.

### `cPacketProperties`

The number of elements in the *pPacketProperties* array.

### `pPacketProperties`

An array of [PACKET_PROPERTY](https://learn.microsoft.com/windows/desktop/api/tpcshrd/ns-tpcshrd-packet_property) structures.

### `cButtons`

Deprecated. Do not use.

### `pguidButtons`

Deprecated. Do not use.

## Remarks

The **PACKET_DESCRIPTION** structure defines the logical layout of the packet. Typically, you do not need to address the contents of a packet. You pass the packets to the Ink object. However, if you need to address the contents of a packet, each packet contains a series of LONG values (properties) followed by one or more DWORD values (button states).

## See also

[AddStroke Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-addstroke)

[GetPreferredPacketDescription Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getpreferredpacketdescription)