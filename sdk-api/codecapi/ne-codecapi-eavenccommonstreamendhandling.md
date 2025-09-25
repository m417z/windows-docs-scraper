# eAVEncCommonStreamEndHandling enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies whether the encoder discards partial groups of pictures (GOPs) at the end of the stream. This enumeration is used with the [AVEncCommonStreamEndHandling](https://learn.microsoft.com/windows/desktop/DirectShow/avenccommonstreamendhandling-property) codec property.

## Constants

### `eAVEncCommonStreamEndHandling_DiscardPartial:0`

If there is a partial GOP at the end of the stream, the encoder will discard it.

### `eAVEncCommonStreamEndHandling_EnsureComplete:1`

If there is a partial GOP at the end of the stream, the encoder will adjust the GOP and encode all of the stream data.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)