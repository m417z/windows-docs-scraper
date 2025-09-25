# IDvdInfo2::GetDefaultAudioLanguage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDefaultAudioLanguage` method retrieves the default audio language.

## Parameters

### `pLanguage` [out]

Receives the default language information.

### `pAudioExtension`

Pointer to a variable of type [DVD_AUDIO_LANG_EXT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_audio_lang_ext) that receives a value indicating the default DVD audio language extension.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | The *pLanguage* parameter is **NULL**. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized. |
| **VFW_E_DVD_INVALIDDOMAIN** | DVD Navigator is not in a valid domain. |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)