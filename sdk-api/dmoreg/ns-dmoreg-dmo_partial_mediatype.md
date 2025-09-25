# DMO_PARTIAL_MEDIATYPE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DMO_PARTIAL_MEDIATYPE` structure partially describes a media type used by a Microsoft DirectX Media Object (DMO). The DMO registration functions use this structure to specify supported media types.

## Members

### `type`

Major type GUID. Use GUID_NULL to match any major type.

### `subtype`

Subtype GUID. Use GUID_NULL to match any subtype.

## See also

[DMO Structures](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-structures)