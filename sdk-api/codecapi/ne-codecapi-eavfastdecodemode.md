# eAVFastDecodeMode enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the video decoding speed. This enumeration is used with the [AVDecVideoFastDecodeMode](https://learn.microsoft.com/windows/desktop/DirectShow/avdecvideofastdecodemode) property.

## Constants

### `eVideoDecodeCompliant:0`

Use normal decoding.

### `eVideoDecodeOptimalLF:1`

Use the optimal loop filter.

### `eVideoDecodeDisableLF:2`

Disable the loop filter.

### `eVideoDecodeFastest:32`

Use the fastest decoding mode.

## See also

[Codec API Enumerations](https://learn.microsoft.com/windows/desktop/DirectShow/codec-api-enumerations)

[ICodecAPI Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-icodecapi)