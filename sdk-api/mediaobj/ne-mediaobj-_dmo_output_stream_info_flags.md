# _DMO_OUTPUT_STREAM_INFO_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_OUTPUT_STREAM_INFO_FLAGS` enumeration defines flags that describe an output stream.

## Constants

### `DMO_OUTPUT_STREAMF_WHOLE_SAMPLES:0x1`

The stream contains whole samples. Samples do not span multiple buffers, and buffers do not contain partial samples.

### `DMO_OUTPUT_STREAMF_SINGLE_SAMPLE_PER_BUFFER:0x2`

Each buffer contains exactly one sample.

### `DMO_OUTPUT_STREAMF_FIXED_SAMPLE_SIZE:0x4`

All the samples in this stream are the same size.

### `DMO_OUTPUT_STREAMF_DISCARDABLE:0x8`

The stream is discardable. Within calls to [IMediaObject::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processoutput), the DMO can discard data for this stream without copying it to an output buffer.

### `DMO_OUTPUT_STREAMF_OPTIONAL:0x10`

The stream is optional. An optional stream is discardable. Also, the application can ignore this stream entirely; it does not have to set the media type for the stream. Optional streams generally contain additional information, or data not needed by all applications.

## Remarks

The DMO_OUTPUT_STREAMF_DISCARDABLE and DMO_OUTPUT_STREAMF_OPTIONAL flags are mutually exclusive. The DMO can set one of these flags (or neither), but not both.

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[IMediaObject::GetOutputStreamInfo](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getoutputstreaminfo)