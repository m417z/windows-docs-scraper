# MPEG_REQUEST_TYPE enumeration

## Description

The **MPEG_REQUEST_TYPE** enumeration type specifies a request for MPEG-2 data.

## Constants

### `MPEG_RQST_UNKNOWN:0`

Unknown request type. Do not use this value.

### `MPEG_RQST_GET_SECTION`

Get one table section. (Synchronous call.)

### `MPEG_RQST_GET_SECTION_ASYNC`

Get one table section. (Asynchronous call.)

### `MPEG_RQST_GET_TABLE`

Get a complete table. (Synchronous call.)

### `MPEG_RQST_GET_TABLE_ASYNC`

Get a complete table. (Asynchronous call.)

### `MPEG_RQST_GET_SECTIONS_STREAM`

Get a stream of sections.

### `MPEG_RQST_GET_PES_STREAM`

Get a stream of packetized elementary stream (PES) packets.

### `MPEG_RQST_GET_TS_STREAM`

Get a stream of transport stream (TS) packets.

### `MPEG_RQST_START_MPE_STREAM`

Get a stream of multi-protocol encapsulation (MPE) packets.

## See also

[BDA Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-types)

[ISectionList::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-isectionlist-initialize)