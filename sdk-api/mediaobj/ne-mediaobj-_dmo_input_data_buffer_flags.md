# _DMO_INPUT_DATA_BUFFER_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_INPUT_DATA_BUFFER_FLAGS` enumeration defines flags that describe an input buffer.

## Constants

### `DMO_INPUT_DATA_BUFFERF_SYNCPOINT:0x1`

The beginning of the data is a synchronization point.

### `DMO_INPUT_DATA_BUFFERF_TIME:0x2`

The buffer's time stamp is valid.

The buffer's indicated time length is valid.

### `DMO_INPUT_DATA_BUFFERF_TIMELENGTH:0x4`

The buffer's indicated time length is valid.

### `DMO_INPUT_DATA_BUFFERF_DISCONTINUITY:0x8`

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[IMediaObject::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-processinput)