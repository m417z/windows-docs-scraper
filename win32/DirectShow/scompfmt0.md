# SCompFmt0 structure

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

> [!Note]
> \[Deprecated. This API may be removed from future releases of Windows.\]

Contains format information for smart recompression.

## Members

**nFormatId**

Reserved; must be zero.

**MediaType**

[**AM\_MEDIA\_TYPE**](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-am_media_type) structure that describes the compression format.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------|
| Header<br> | Qedit.h |

## See also

[**IAMTimelineGroup::GetSmartRecompressFormat**](https://learn.microsoft.com/windows/win32/directshow/iamtimelinegroup-getsmartrecompressformat)

[**IAMTimelineGroup::SetSmartRecompressFormat**](https://learn.microsoft.com/windows/win32/directshow/iamtimelinegroup-setsmartrecompressformat)

