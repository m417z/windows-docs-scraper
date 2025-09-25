# MSVidSinkStreams enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **MSVidSinkStreams** enumeration defines the stream types for a generic sink.

## Constants

### `MSVidSink_Video:1`

### `MSVidSink_Audio:2`

### `MSVidSink_Other:4`

#### - Audio

Indicates an audio stream.

#### - Other

Indicates a stream that is neither video nor audio.

#### - Video

Indicates a video steam.

## See also

[IMSVidGenericSink::get_SinkStreams](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidgenericsink-get_sinkstreams)

[IMSVidGenericSink::put_SinkStreams](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidgenericsink-put_sinkstreams)

[Video Control Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/video-control-enumerations)