# AM_DvdKaraokeData structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies how to mix the karaoke audio channels.

## Members

### `dwDownmix`

A bitwise OR of [DVD_KARAOKE_DOWNMIX](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-dvd_karaoke_downmix) flags telling the decoder which channels are downmixed to channels 0 or 1.

### `dwSpeakerAssignment`

A valid [DVD_KARAOKE_ASSIGNMENT](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-dvd_karaoke_assignment) value that indicates which speakers the output is going to.

## Remarks

This structure is used for the AM_PROPERTY_DVDKARAOKE_DATA property.

## See also

[DVD Karaoke Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-karaoke-property-set)

[SelectKaraokeAudioPresentationMode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectkaraokeaudiopresentationmode)