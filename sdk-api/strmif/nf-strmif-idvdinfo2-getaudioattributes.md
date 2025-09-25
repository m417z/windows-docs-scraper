# IDvdInfo2::GetAudioAttributes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetAudioAttributes` method retrieves the attributes of the specified audio stream in the current title or menu.

## Parameters

### `ulStream` [in]

Variable of type ULONG specifying the audio stream whose attributes you wish to query. See Remarks.

### `pATR` [out]

Pointer to a [DVD_AudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_audioattributes) structure that is filled with the attributes of the specified audio stream.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized. |
| **VFW_E_DVD_NO_ATTRIBUTES** | The stream's audio attributes are not available. |
| **E_POINTER** | Invalid argument. |

## Remarks

*ulStream* can be any index number from 0 through 7 or one of the following values:

| Value | Description |
| --- | --- |
| DVD_DEFAULT_AUDIO_STREAM | To query for the attributes of the default audio stream. |
| DVD_STREAM_DATA_CURRENT | To query the current stream. |
| DVD_STREAM_DATA_VMGM | To query for the VMGM's audio attributes. |
| DVD_STREAM_DATA_VTSM | To query for the VTSM's audio attributes. |

The use of this method is demonstrated in the DVDSample application in **CDvdCore::GetAudioAttributes** and **CAudioLangDlg::GetAudioLang**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)