# MPEG_RQST_PACKET structure

## Description

The **MPEG_RQST_PACKET** structure defines a buffer to receive MPEG-2 section data.

## Members

### `dwLength`

Specifies the length of the buffer that **pSection** points to. The minimum size for section data is 4096 bytes.

### `pSection`

Pointer to a buffer that receives the section data. The pointer is typed as a [SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section) structure. The first bytes in the section contain header fields that are defined in the **SECTION** structure. The **SectionData** member of the **SECTION** structure is an array of bytes, containing the body of the section after the header bytes.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)

[MPEG_PACKET_LIST Structure](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_packet_list)