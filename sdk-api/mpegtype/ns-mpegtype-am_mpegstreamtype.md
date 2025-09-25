# AM_MPEGSTREAMTYPE structure

## Description

The **AM_MPEGSTREAMTYPE** structure defines the media type for an MPEG-1 program stream.

## Members

### `dwStreamId`

Stream identifier of the stream to process.

### `dwReserved`

Reserved.

### `mt`

[AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure describing the type for the substeam. The **pbFormat** member of this structure must **NULL**. The format data normally conveyed in **pbFormat** is stored in the **bFormat** member.

### `bFormat`

Format data. The size of this array, in bytes, is given in the **mt.cbFormat** member.

## See also

[AM_MPEGSYSTEMTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpegtype/ns-mpegtype-am_mpegsystemtype)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[MEPG-1 Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-1-media-types)