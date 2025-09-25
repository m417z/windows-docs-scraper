# DVD_KaraokeAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_KaraokeAttributes` structure contains information about a karaoke audio stream. The [IDvdInfo2::GetKaraokeAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getkaraokeattributes) method fills in a `DVD_KaraokeAttributes` structure for a specified stream.

## Members

### `bVersion`

Version number. The current karaoke version is 1.0.

### `fMasterOfCeremoniesInGuideVocal1`

If **TRUE**, the "Guide Vocal 1" channel contains the "Master of Ceremonies" content.

### `fDuet`

A Boolean value indicating whether the song is intended to be sung as a duet.

### `ChannelAssignment`

A [DVD_KARAOKE_ASSIGNMENT](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-dvd_karaoke_assignment) value indicating the speaker configuration into which all the channels will be mixed.

### `wChannelContents`

An array of valid [DVD_KARAOKE_CONTENTS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_karaoke_contents) values that identifies the content on each channel.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)