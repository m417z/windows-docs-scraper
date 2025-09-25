# CHANNEL_PDU_HEADER structure

## Description

Contains information about a data block being received by the server end of a virtual channel.

## Members

### `length`

Size, in bytes, of the data block, excluding this header.

### `flags`

Information about the data block. The following bit flags will be set. Note that you should not make direct
comparisons using the '==' operator when comparing the values in the following list; instead, use the comparison
methods described in the list.

#### CHANNEL_FLAG_FIRST (1)

The chunk is the beginning of the data written by a single write operation.

Use bitwise comparisons when comparing this flag.

#### CHANNEL_FLAG_LAST (2)

The chunk is the end of the data written by a single write operation.

Use bitwise comparisons when comparing this flag.

#### CHANNEL_FLAG_MIDDLE (0)

This is the default. The chunk is in the middle of a block of data written by a single write operation.

Do not use bitwise comparisons to compare this flag value directly. Instead, use bitwise comparisons to
determine that the flag value is not **CHANNEL_FLAG_FIRST** or
**CHANNEL_FLAG_LAST**. This is done by using the following comparison:

`Result = !(flags & CHANNEL_FLAG_FIRST) && !(flags & CHANNEL_FLAG_LAST)`

#### CHANNEL_FLAG_ONLY (3)

Combines the **CHANNEL_FLAG_FIRST** and **CHANNEL_FLAG_LAST** values. The chunk contains all the data from a single write operation.

Use bitwise comparisons when comparing this flag.

## Remarks

In certain cases, Remote Desktop Services places a
**CHANNEL_PDU_HEADER** structure at the beginning
of each chunk of data read by a call to the
[WTSVirtualChannelRead](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelread) function. This will
occur if the client DLL sets the **CHANNEL_OPTION_SHOW_PROTOCOL** option when it calls the
[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit) function to initialize the
virtual channel. This will also occur if the channel is a dynamic virtual channel written to by using the
[IWTSVirtualChannel::Write](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-write) method.

## See also

[IWTSVirtualChannel::Write](https://learn.microsoft.com/windows/desktop/api/tsvirtualchannels/nf-tsvirtualchannels-iwtsvirtualchannel-write)

[VirtualChannelInit](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelinit)

[VirtualChannelWrite](https://learn.microsoft.com/windows/desktop/api/cchannel/nc-cchannel-virtualchannelwrite)

[WTSVirtualChannelRead](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelread)