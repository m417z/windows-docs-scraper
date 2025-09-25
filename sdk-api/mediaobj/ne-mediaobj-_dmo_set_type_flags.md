# _DMO_SET_TYPE_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_SET_TYPE_FLAGS` enumeration defines flags for setting the media type on a stream.

## Constants

### `DMO_SET_TYPEF_TEST_ONLY:0x1`

Test the media type but do not set it.

### `DMO_SET_TYPEF_CLEAR:0x2`

Clear the media type that was set for the stream.

## Remarks

The DMO_SET_TYPEF_TEST_ONLY and DMO_SET_TYPEF_CLEAR flags are mutually exclusive. Do not set both flags.

## See also

[DMO Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-enumerated-types)

[IMediaObject::SetInputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setinputtype)

[IMediaObject::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-setoutputtype)