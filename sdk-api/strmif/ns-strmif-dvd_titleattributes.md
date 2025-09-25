# DVD_TitleAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DVD_TitleAttributes** structure contains information about a DVD title.

## Members

### `AppMode`

A variable of type [DVD_TITLE_APPMODE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_title_appmode) indicating whether the Navigator is in karaoke mode.

### `TitleLength`

A [DVD_HMSF_TIMECODE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_hmsf_timecode) structure.

### `VideoAttributes`

A [DVD_VideoAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_videoattributes) structure containing information about the "main" video of the current menu or title.

### `ulNumberOfAudioStreams`

The number of audio streams available in the title.

### `AudioAttributes`

An array of [DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes) structures containing information about each available audio stream in the current title.

### `MultichannelAudioAttributes`

An array of [DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes) structure.

### `ulNumberOfSubpictureStreams`

The number of subpicture streams available in the title.

### `SubpictureAttributes`

An array of [DVD_SubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_subpictureattributes) structures that contain information about each available subpicture stream in the title.

## Remarks

By default, the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) uses the **AppMode** member of the anonymous union to report the title mode.

If the application sets the **DVD_EnableTitleLength** option to **TRUE**, the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) uses the **TitleLength** member of the union to report the title length. To set this option, call the [IDvdControl2::SetOption](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setoption) method.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IDvdInfo2::GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes)