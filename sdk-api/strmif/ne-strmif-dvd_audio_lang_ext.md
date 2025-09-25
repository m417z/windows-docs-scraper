# DVD_AUDIO_LANG_EXT enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Defines flags that indicate whether an audio stream contains audio language extensions.

## Constants

### `DVD_AUD_EXT_NotSpecified:0`

The DVD doesn't specify an audio language extension for this audio stream.

### `DVD_AUD_EXT_Captions:1`

The audio stream contains captions.

### `DVD_AUD_EXT_VisuallyImpaired:2`

The audio stream contains content for people with low vision.

### `DVD_AUD_EXT_DirectorComments1:3`

The audio stream contains "director comments 1."

### `DVD_AUD_EXT_DirectorComments2:4`

The audio stream contains "director comments 2."

## Remarks

This enumeration is used in the [IDvdInfo2::GetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudioattributes) and [IDvdInfo2::GetDefaultAudioLanguage](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdefaultaudiolanguage) methods.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IDvdInfo2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)