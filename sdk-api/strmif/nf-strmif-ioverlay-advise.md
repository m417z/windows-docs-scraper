# IOverlay::Advise

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Advise` method sets up an advise link for the overlay events specified by the *dwInterests* parameter.

## Parameters

### `pOverlayNotify` [in]

Pointer to the notification interface.

### `dwInterests` [in]

Callbacks of interest, which can be any subset of the following events.

| Event | Description |
| --- | --- |
| ADVISE_NONE | No changes. |
| ADVISE_CLIPPING | Change in clipping region (synchronized with the window). |
| ADVISE_PALETTE | Change in palette. |
| ADVISE_COLORKEY | Change of chroma key value. |
| ADVISE_POSITION | Change in position of video window (not synchronized with the window). |
| ADVISE_DISPLAY_CHANGE | Called on [WM_DISPLAYCHANGE](https://learn.microsoft.com/windows/desktop/gdi/wm-displaychange). The **WM_DISPLAYCHANGE** message is sent to all windows when the display resolution has changed. |
| ADVISE_ALL2 | All of the above. |

## Return value

Returns S_OK if successful. If the method fails, it returns an **HRESULT** error code.

## Remarks

This method sets up an advise link for the [IOverlayNotify](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlaynotify) interface to receive notifications. If one of these events occurs, the appropriate entry point in the *pOverlayNotify* parameter passed in is called ([IOverlayNotify::OnClipChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-onclipchange), [IOverlayNotify::OnColorKeyChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-oncolorkeychange), [IOverlayNotify::OnPaletteChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-onpalettechange), or [IOverlayNotify::OnPositionChange](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlaynotify-onpositionchange)).

Only one advise link can be set on any given [IOverlay](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay) interface. Trying to set another notification interface on second and subsequent calls returns VFW_E_ADVISE_ALREADY_SET. You can cancel an advise link by using [IOverlay::Unadvise](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ioverlay-unadvise).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IOverlay Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ioverlay)