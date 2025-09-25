# _AM_FILTER_MISC_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **_AM_FILTER_MISC_FLAGS** enumeration contains flags that indicate whether a filter is a source filter or a renderer filter.

## Constants

### `AM_FILTER_MISC_FLAGS_IS_RENDERER:0x1`

The filter is a renderer and sends an [EC_COMPLETE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-complete) event at the end of the stream.

### `AM_FILTER_MISC_FLAGS_IS_SOURCE:0x2`

The filter is a source filter.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMFilterMiscFlags::GetMiscFlags](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamfiltermiscflags-getmiscflags)