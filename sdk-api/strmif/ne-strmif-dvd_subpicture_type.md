# DVD_SUBPICTURE_TYPE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines flags used to determine what kind of content the subpicture stream contains.

## Constants

### `DVD_SPType_NotSpecified:0`

The DVD does not specify the subpicture type.

### `DVD_SPType_Language:1`

The subpicture contains language-related content such as movie subtitles or other text.

### `DVD_SPType_Other:2`

The subpicture contains nonlanguage-related content such as a bouncing ball in karaoke titles.

## See also

[DVD_SubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_subpictureattributes)

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)