# DVD_MultichannelAudioAttributes structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `DVD_MultichannelAudioAttributes` structure describes the multichannel attributes of one audio stream within a specified title.

## Members

### `Info`

Array of eight [DVD_MUA_MixingInfo](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_mua_mixinginfo) structures, which contain the mixing information for each channel in the audio stream.

### `Coeff`

Array of eight [DVD_MUA_Coeff](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_mua_coeff) structures, which contain the mixing coefficients for each channel in the audio stream.

## Remarks

The [DVD_TitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_titleattributes) structure contains an array of up to eight **DVD_MultichannelAudioAttributes** structures. When `DVD_TitleAttributes` is filled by a call to the [IDvdInfo2::GetTitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-gettitleattributes) method, the array will be populated with one **DVD_MultichannelAudioAttributes** structure for each available audio stream in the title.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)