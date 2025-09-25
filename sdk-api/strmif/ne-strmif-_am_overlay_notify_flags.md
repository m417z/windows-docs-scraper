# _AM_OVERLAY_NOTIFY_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The AM_OVERLAY_NOTIFY_FLAGS enumeration indicates what the overlay has changed, or is about to change.

## Constants

### `AM_OVERLAY_NOTIFY_VISIBLE_CHANGE:0x1`

The rectangle will be changed from visible to invisible, or vice-versa.

### `AM_OVERLAY_NOTIFY_SOURCE_CHANGE:0x2`

Source rectangle changed or changing.

### `AM_OVERLAY_NOTIFY_DEST_CHANGE:0x4`

Destination rectangle changed or changing.

## Remarks

The [IDDrawExclModeVideoCallback::OnUpdateOverlay](https://learn.microsoft.com/windows/win32/api/strmif/nf-strmif-iddrawexclmodevideocallback-onupdateoverlay) method uses these flags to indicate how the overlay has changed, so that applications can take the necessary steps.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDDrawExclModeVideoCallback::OnUpdateOverlay](https://learn.microsoft.com/windows/win32/api/strmif/nf-strmif-iddrawexclmodevideocallback-onupdateoverlay)