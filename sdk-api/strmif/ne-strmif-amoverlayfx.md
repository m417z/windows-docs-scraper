# AMOVERLAYFX enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies effects on a DirectDraw hardware overlay surface.

## Constants

### `AMOVERFX_NOFX:0`

Normal video (no effects).

### `AMOVERFX_MIRRORLEFTRIGHT:0x2`

Mirror the overlay across the vertical axis.

### `AMOVERFX_MIRRORUPDOWN:0x4`

Mirror the overlay across the horizontal axis.

### `AMOVERFX_DEINTERLACE:0x8`

When used in [IAMOverlayFX::QueryOverlayFXCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamoverlayfx-queryoverlayfxcaps), this flag specifies whether the hardware can support the DirectDraw 7 DDOVERFX_DEINTERLACE hint. When used with the [IAMOverlayFX::GetOverlayFX](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamoverlayfx-getoverlayfx) or [IAMOverlayFX::SetOverlayFX](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamoverlayfx-setoverlayfx) methods, this flag indicates that the overlay should be deinterlaced if possible.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMOverlayFX Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamoverlayfx)