# IDvdControl2::SelectKaraokeAudioPresentationMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectKaraokeAudioPresentationMode` method sends karaoke auxiliary channels to the left or right speakers.

## Parameters

### `ulMode` [in]

Bitwise OR of [DVD_KARAOKE_DOWNMIX](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-dvd_karaoke_downmix) enumeration indicating how to downmix the five karaoke channels to channels 0 and 1, which are usually output to the left and right speakers.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_PROP_SET_UNSUPPORTED** | The audio decoder does not support downmixing. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter is in an invalid domain. |
| **VFW_E_DVD_OPERATION_INHIBITED** | UOP control prohibits the current operation. |

## Remarks

When the DVD Navigator enters karaoke mode, it queries the audio decoder to discover whether it supports karaoke downmixing. If the decoder supports it, then channels 2 through 4 (the karaoke auxiliary channels with the guide vocals, guide melodies, and sound effects) are muted. Use this method to turn individual channels on or off and direct them to channels 0 and 1.

This method is demonstrated in the DVDSample application in **CKaraokeDlg::DoModal**.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| Karaoke_Audio_Presentation_Mode_Change | * DVD_DOMAIN_VideoManagerMenu<br>* DVD_DOMAIN_VideoTitleSetMenu<br>* DVD_DOMAIN_Title<br>* DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[DVD Karaoke Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-karaoke-property-set)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)