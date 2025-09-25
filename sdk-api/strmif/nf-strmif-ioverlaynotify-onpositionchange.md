# IOverlayNotify::OnPositionChange

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnPositionChange` method provides notification that the position has changed.

## Parameters

### `pSourceRect` [in]

Pointer to the source video rectangle.

### `pDestinationRect` [in]

Pointer to the destination video rectangle. Note that this is not clipped to the visible display area.

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

This method is a callback intended for use by hardware overlay cards that do not want the expense of synchronous clipping updates, and just want to know when the source or destination video positions change.

Unlike the [IOverlayNotify::OnClipChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-onclipchange) method, this method is not called in synchronization with the window changing but, rather, at some point after the window has changed (basically in time with WM_SIZE messages received). This is therefore suitable for overlay cards that do not inlay their data to the frame buffer.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlayNotify Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlaynotify)