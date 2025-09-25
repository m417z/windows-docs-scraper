# tagKS_BDA_FRAME_INFO structure

## Description

The KS_BDA_FRAME_INFO structure describes BDA extensions to the KSSTREAM_HEADER structure, which describes a packet of data to be read from or written to a streaming driver pin.

## Members

### `ExtendedHeaderSize`

Size, in bytes, of the BDA extensions described in this extended header structure.

### `dwFrameFlags`

Flags specific to BDA extensions.

### `ulEvent`

Identifier of an event.

### `ulChannelNumber`

Channel number of a television program.

### `ulSubchannelNumber`

Subchannel number of a television program.

### `ulReason`

Identifies the reason the packet was transferred.

## See also

[KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header)