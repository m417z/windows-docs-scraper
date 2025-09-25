# DVD_TITLE_APPMODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Indicates whether a DVD title is a karaoke title. This enumeration is a member of the [DVD_TitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_titleattributes) structure, which is filled when an application calls the [IDvdInfo2::GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes) method.

## Constants

### `DVD_AppMode_Not_Specified:0`

The disc does not provide any application mode information about this title.

### `DVD_AppMode_Karaoke:1`

Title contains karaoke content.

### `DVD_AppMode_Other:3`

Title contains a type of content that the [DVD Navigator Filter](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) does not recognize, so the application should treat the title as a regular DVD-Video title.

## Remarks

When the DVD Navigator encounters a karaoke title on a disc, it goes into "karaoke mode" and informs the audio decoder. The decoder must respond by initially muting the three auxiliary channels. Applications can then selectively control the volume and mixing configuration of these channels using the karaoke-related methods in the [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) interface For more information, see [Playing Karaoke Audio Streams](https://learn.microsoft.com/windows/desktop/DirectShow/playing-karaoke-audio-streams).

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)