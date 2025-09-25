# DVD_MenuAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DVD_MenuAttributes** structure contains information about a DVD menu. The [IDvdInfo2::GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes) method fills in a DVD_MenuAttributes structure for a specified stream.

## Members

### `fCompatibleRegion`

An array of **TRUE**/**FALSE** values indicating with which DVD regions the disc's authored region is compatible. The eight array indexes (numbered 0-7) correspond to the eight DVD regions (numbered 1-8). This array is only filled in when the menu being queried is the Video Manager Menu (the main menu for the entire disc).

**Important** A value of 0 (**FALSE**) indicates that the region is compatible (permitted). A value of 1 (**TRUE**) indicates that the region is not compatible. This member should have been named *fIncompatibleRegion*.

### `VideoAttributes`

A [DVD_VideoAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_videoattributes) structure containing the video attributes of the menu. This applies to both a VMGM and VTSM.

### `fAudioPresent`

A variable of type BOOL indicating whether the menu has an audio stream.

### `AudioAttributes`

A [DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes) structure containing information about the menu's audio stream. This structure will only be filled in if *fAudioPresent* is **TRUE**.

### `fSubpicturePresent`

A variable of type BOOL indicating whether the menu has a subpicture stream.

### `SubpictureAttributes`

A [DVD_SubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_subpictureattributes) structure containing information about the menu's subpicture stream. This structure will only be filled in if *fSubpicturePresent* is **TRUE**.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)