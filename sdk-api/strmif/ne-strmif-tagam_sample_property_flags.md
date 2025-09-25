# tagAM_SAMPLE_PROPERTY_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies values for the [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure. These values describe the properties of media samples.

## Constants

### `AM_SAMPLE_SPLICEPOINT:0x1`

Sample is a splice point (it can be decoded without reference to previous data).

### `AM_SAMPLE_PREROLL:0x2`

Sample is a preroll sample.

### `AM_SAMPLE_DATADISCONTINUITY:0x4`

Initial data in this sample is a splice point. The data in the previous sample was not intended to be followed by data in this sample. For more information, see Remarks.

### `AM_SAMPLE_TYPECHANGED:0x8`

Sample type changed.

### `AM_SAMPLE_TIMEVALID:0x10`

Time is valid.

### `AM_SAMPLE_TIMEDISCONTINUITY:0x40`

A time gap in the data starts after this sample. The [AM_SAMPLE2_PROPERTIES](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_sample2_properties) structure can be **NULL** in this case.

### `AM_SAMPLE_FLUSH_ON_PAUSE:0x80`

For live data only; indicates discard in the paused state.

### `AM_SAMPLE_STOPVALID:0x100`

Stop time is valid.

### `AM_SAMPLE_ENDOFSTREAM:0x200`

End of stream occurs after this sample. This flag is reserved for kernel streaming. DirectShow currently does not use it.

### `AM_STREAM_MEDIA:0`

Normal data stream identifier.

### `AM_STREAM_CONTROL:1`

Control stream identifier. A value greater than 0x7FFFFFFF indicates an application-defined stream.

## Remarks

The **AM_SAMPLE_DATADISCONTINUITY** flag indicates that the data in the current media sample is not considered contiguous with the data in previous samples. A filter receiving a sample with the **AM_SAMPLE_DATADISCONTINUITY** flag set should not discard unprocessed data in its buffers. A filter waiting for incoming data before it can process buffered data should process the buffered data immediately; so, buffered data might be discarded if it is incomplete.

For example, a video decompressor filter might receive a media sample with the **AM_SAMPLE_DATADISCONTINUITY** flag set when it has two complete compressed video frames and one incomplete compressed video frame in its buffers. In this case, the filter decompresses the two complete frames and discards the incomplete third frame before beginning to process data from the current media sample.

The **AM_SAMPLE_DATADISCONTINUITY** flag is set on the first sample received following a flush or a stop. In addition, you should use the **AM_SAMPLE_DATADISCONTINUITY** flag when content is switched in the source, when a channel change occurs (when there might also be a format change), or when there is missing data because of stream interruptions.

The **AM_SAMPLE_DATADISCONTINUITY** flag is equivalent to the [IMediaSample::IsDiscontinuity](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-isdiscontinuity) method returning **S_OK**.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)