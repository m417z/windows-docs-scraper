# MPEG_PACKET_LIST structure

## Description

The **MPEG_PACKET_LIST** structure contains a list of MPEG-2 sections.

## Members

### `wPacketCount`

Specifies the size of the **PacketList** array.

### `PacketList`

Specifies a pointer to an array of [MPEG_RQST_PACKET](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_rqst_packet) structures, which themselves contain pointers to buffers that hold the sectioned data.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)

[MPEG_STREAM_BUFFER Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_stream_buffer)