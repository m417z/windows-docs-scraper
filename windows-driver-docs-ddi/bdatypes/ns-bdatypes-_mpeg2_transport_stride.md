# _MPEG2_TRANSPORT_STRIDE structure

## Description

The MPEG2_TRANSPORT_STRIDE structure describes the format block of the MPEG2 transport stride.

## Members

### `dwOffset`

Offset in bytes into a packet.

### `dwPacketLength`

Size in bytes of a packet.

### `dwStride`

Stride of data in a packet.

## Remarks

The MPEG2 transport stride format block is associated with the MEDIATYPE_Stream/MEDIASUBTYPE_MPEG2_TRANSPORT_STRIDE media type. Format blocks that are associated with this media type must start with the MPEG2_TRANSPORT_STRIDE structure.