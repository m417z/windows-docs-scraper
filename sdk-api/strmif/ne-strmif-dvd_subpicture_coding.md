# DVD_SUBPICTURE_CODING enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates what kind of content the subpicture stream contains.

## Constants

### `DVD_SPCoding_RunLength:0`

Indicates that the subpicture uses run length encoding.

### `DVD_SPCoding_Extended:1`

Indicates that subpicture uses extended encoding.

### `DVD_SPCoding_Other:2`

Indicates that the subpicture uses some other encoding scheme.

## Remarks

Most subpicture streams contain language-related content such as movie subtitles, but subpictures can also be used for the bouncing ball in karaoke or other non-language-related purposes.

## See also

[DVD_SubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_subpictureattributes)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)