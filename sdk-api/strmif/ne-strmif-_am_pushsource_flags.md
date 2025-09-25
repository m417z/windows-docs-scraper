# _AM_PUSHSOURCE_FLAGS enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates the behavior of a live source filter.

## Constants

### `AM_PUSHSOURCECAPS_INTERNAL_RM:0x1`

The filter uses its own rate-matching mechanism; the renderer should therefore not attempt to match rates with this filter.

### `AM_PUSHSOURCECAPS_NOT_LIVE:0x2`

The filter is not live. Do not treat it as a live source, even though it exposes the [IAMPushSource](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iampushsource) interface.

### `AM_PUSHSOURCECAPS_PRIVATE_CLOCK:0x4`

The filter time stamps the samples using a private clock. The clock is not available to the rest of the graph through [IReferenceClock](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ireferenceclock).

### `AM_PUSHSOURCEREQS_USE_STREAM_CLOCK:0x10000`

Reserved; do not use.

### `AM_PUSHSOURCEREQS_USE_CLOCK_CHAIN:0x20000`

## Remarks

If no flags are set (the default case), the source filter is assumed to be live and not to perform any rate matching on its own.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)