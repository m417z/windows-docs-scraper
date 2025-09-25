# IOverlayNotify::OnClipChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnClipChange` method provides notification that the window's visible region has changed. It is essential that any overlay hardware be updated to reflect the change to the visible region before returning from this method.

## Parameters

### `pSourceRect` [in]

Pointer to the region of the video to use.

### `pDestinationRect` [in]

Pointer to the video destination.

### `pRgnData` [in]

Pointer to the clipping information.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

The calls to `OnClipChange` happen in synchronization with the window. It is called with an empty clip list to freeze the video before the window moves, and then called again when the window has stabilized with the new clip list.

If the window rectangle is all zeros, the window is invisible. As is the case for AVI decoders, the decoder should save the image if it relies on the current image to decode the next one.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlayNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlaynotify)