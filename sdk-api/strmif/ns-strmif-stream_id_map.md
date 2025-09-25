# STREAM_ID_MAP structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `STREAM_ID_MAP` structure describes an elementary stream within an MPEG-2 program stream. Used with the [IEnumStreamIdMap](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ienumstreamidmap) interface methods.

## Members

### `stream_id`

Specifies the ID of the PES stream.

### `dwMediaSampleContent`

Specifies the media contents of the stream. May be one of the following values defined in axextend.idl:

#### MPEG2_PROGRAM_STREAM_MAP (0x00000000)

#### MPEG2_PROGRAM_ELEMENTARY_STREAM (0x00000001)

#### MPEG2_PROGRAM_DIRECTORY_PES_PACKET (0x00000002)

#### MPEG2_PROGRAM_PACK_HEADER (0x00000003)

#### MPEG2_PROGRAM_PES_STREAM (0x00000004)

#### MPEG2_PROGRAM_SYSTEM_HEADER (0x00000005)

### `ulSubstreamFilterValue`

Specifies the substream within the elementary stream. If no substream filtering is required, use SUBSTREAM_FILTER_VAL_NONE (0x10000000).

### `iDataOffset`

Specifies the offset in bytes for the substream. If no filtering is required, specify 0.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)