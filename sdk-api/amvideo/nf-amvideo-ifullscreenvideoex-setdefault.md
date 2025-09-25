# IFullScreenVideoEx::SetDefault

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDefault` method saves the current settings.

## Return value

Returns an **HRESULT** value.

## Remarks

Normally, the properties set through this interface apply only to the current instance of the Full Screen Renderer. Calling this method saves the current values as the global default. This method persists the following information:

* The clip factor.
* The enabled flag for each display mode.

It does not persist the caption or the hide-when-deactivated flag.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IFullScreenVideoEx Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-ifullscreenvideoex)

[IFullScreenVideoEx::HideOnDeactivate](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-hideondeactivate)

[IFullScreenVideoEx::SetCaption](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-setcaption)

[IFullScreenVideoEx::SetClipFactor](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-setclipfactor)

[IFullScreenVideoEx::SetEnabled](https://learn.microsoft.com/windows/desktop/api/amvideo/nf-amvideo-ifullscreenvideoex-setenabled)