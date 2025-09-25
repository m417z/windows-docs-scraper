# MPEG_STREAM_BUFFER structure

## Description

The **MPEG_STREAM_BUFFER** structure defines a buffer that receives MPEG-2 data.

## Members

### `hr`

Specifies a status code. Use this value to check the status of the read request.

### `dwDataBufferSize`

Specifies the size of the buffer, in bytes.

### `dwSizeOfDataRead`

Specifies the amount of valid data in the buffer, in bytes

### `pDataBuffer`

Pointer to a buffer that holds the MPEG-2 data.

## Remarks

This structure is used with the [IMpeg2Stream::SupplyDataBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-impeg2stream-supplydatabuffer) method to get raw MPEG-2 data.

For PSI tables and sections, set **pDataBuffer** to point to a [SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section) structure. If you also create an [MPEG_PACKET_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_packet_list) structure to hold a list of buffers, you can pass that list to the [ISectionList::InitializeWithRawSections](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-isectionlist-initializewithrawsections) method.

#### Examples

The following code shows how to initialize an **MPEG_STREAM_BUFFER** structure so that it points to a **SECTION** structure contained in an **MPEG_PACKET_LIST** section list:

```cpp

// Allocate two buffers for section data.
const int cBufferSize = 4096;
BYTE pBuffer1[cBufferSize];
BYTE pBuffer2[cBufferSize];

// Create a packet list to hold both buffers.
MPEG_RQST_PACKET RqstPacket[2];
MPEG_PACKET_LIST Packets;

RqstPacket[0].dwLength = cBufferSize;
RqstPacket[0].pSection = (SECTION*)pBuffer1;
RqstPacket[1].dwLength = cBufferSize;
RqstPacket[1].pSection = (SECTION*)pBuffer2;

Packets.wPacketCount = 2;
Packets.PacketList[0] = &RqstPacket[0];
Packets.PacketList[1] = &RqstPacket[1];

// Set the stream buffer structure to point to the first packet in the list.
MPEG_STREAM_BUFFER StreamBuffer;
ZeroMemory(&StreamBuffer, sizeof(MPEG_STREAM_BUFFER));
StreamBuffer.dwDataBufferSize = Packets.PacketList[0]->dwLength;
StreamBuffer.pDataBuffer = (BYTE*) Packets.PacketList[0]->pSection;

```

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)