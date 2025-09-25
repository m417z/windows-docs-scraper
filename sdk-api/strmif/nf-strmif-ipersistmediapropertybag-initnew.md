# IPersistMediaPropertyBag::InitNew

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `InitNew` method initializes the object to receive new properties.

## Return value

Returns S_OK.

## Remarks

Calling this method on the [AVI Mux](https://learn.microsoft.com/windows/desktop/DirectShow/avi-mux-filter) filter clears any properties that were previously set using the [Load](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ipersistmediapropertybag-load) method.

Calling this method on the [AVI Splitter](https://learn.microsoft.com/windows/desktop/DirectShow/avi-splitter-filter) filter or the [WAVE Parser](https://learn.microsoft.com/windows/desktop/DirectShow/wave-parser-filter) filter has no effect.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IPersistMediaPropertyBag Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipersistmediapropertybag)