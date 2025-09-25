# IVPBaseNotify::RenegotiateVPParameters

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RenegotiateVPParameters` method initializes the connection to the decoder.

## Return value

Returns an **HRESULT** value.

## Remarks

The [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter negotiates various parameters (by using the [IVPBaseConfig](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpbaseconfig) interface) with the decoder or driver. Call this method if any of those parameters (such as the video format or size) change. Currently, the Overlay Mixer repeats the whole connection process. You can call this method even while the graph is playing.

Include Vptype.h before Vpnotify.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPBaseNotify Interface](https://learn.microsoft.com/windows/desktop/api/vpnotify/nn-vpnotify-ivpbasenotify)