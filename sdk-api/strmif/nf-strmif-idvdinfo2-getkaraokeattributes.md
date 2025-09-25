# IDvdInfo2::GetKaraokeAttributes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetKaraokeAttributes` method retrieves the karaoke attributes of the specified audio stream in the current title or menu.

## Parameters

### `ulStream` [in]

Specifies the index of the audio stream whose attributes you want to query. See Remarks.

### `pAttributes` [out]

Pointer to a [DVD_KaraokeAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_karaokeattributes) structure that is filled with the karaoke attributes.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized. |
| **VFW_E_DVD_NOT_IN_KARAOKE_MODE** | The specified stream is not in karaoke format. |
| **VFW_E_DVD_INVALIDDOMAIN** | The DVD Navigator is not in the title domain. |
| **VFW_E_DVD_NO_ATTRIBUTES** | The karaoke attributes for the specified stream are not available. |

## Remarks

This method does not explicitly return the number of channels in the stream. You can obtain that information through a call to [IDvdInfo2::GetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getaudioattributes). This method is demonstrated in the DVDSample application in **CKaraokeDlg::DoModal**.

The *ulStream* parameter may be a value from 0 through 7, or one of the following:

| Value | Description |
| --- | --- |
| DVD_STREAM_DATA_CURRENT (0x800) | To query the currently selected audio stream. |
| DVD_DEFAULT_AUDIO_STREAM | To query the default audio stream. |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)