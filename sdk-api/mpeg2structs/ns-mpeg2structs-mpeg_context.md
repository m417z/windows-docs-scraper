# MPEG_CONTEXT structure

## Description

The **MPEG_CONTEXT** structure identifies the source of an MPEG-2 data stream.

## Members

### `Type`

Specifies the source type, as an [MPEG_CONTEXT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ne-mpeg2structs-mpeg_context_type) value. Currently, the value must be MPEG_CONTEXT_BCS_DEMUX.

### `U`

A union that contains the following members.

### `U.Demux`

Specifies an [MPEG_BCS_DEMUX](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_bcs_demux) structure that identifies the filter graph instance.

### `U.Winsock`

Currently not supported.

## See also

[BDA Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/bda-structures)