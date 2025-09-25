# MFSTREAMSINK_MARKER_TYPE enumeration

## Description

Defines stream marker information for the [IMFStreamSink::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) method. The [PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfstreamsink-placemarker) method places a marker on the stream between samples. The **MFSTREAMSINK_MARKER_TYPE** enumeration defines the marker type and the type of information associated with the marker.

## Constants

### `MFSTREAMSINK_MARKER_DEFAULT:0`

This marker is for the application's use and does not convey any information to the stream sink.

### `MFSTREAMSINK_MARKER_ENDOFSEGMENT`

This marker indicates the end of a segment within a presentation. There might be a gap in the stream until the next segment starts. There is no data associated with this marker.

### `MFSTREAMSINK_MARKER_TICK`

This marker indicates that there is a gap in the stream. The marker data is a **LONGLONG** value (VT_I8) that specifies the time for the missing sample. The next sample received after this marker might but will not necessarily have the discontinuity flag: the data might remain continuous after the time gap. This marker corresponds to an [MEStreamTick](https://learn.microsoft.com/windows/desktop/medfound/mestreamtick) event from the stream.

### `MFSTREAMSINK_MARKER_EVENT`

This marker contains a media event. The marker data is a pointer to the event's [IMFMediaEvent](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaevent) interface (VT_UNKNOWN).

## Remarks

If the [Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer) receives an **MFSTREAMSINK_MARKER_TICK** marker, it inserts silence to cover the gap in the data.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)