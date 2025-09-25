# IDvdControl2::SelectDefaultAudioLanguage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectDefaultAudioLanguage` method sets the default audio language.

## Parameters

### `Language` [in]

Locale identifier that specifies the default language.

### `audioExtension` [in]

[DVD_AUDIO_LANG_EXT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_audio_lang_ext) enumeration that specifies the default audio language extension.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *audioExtension* value is invalid. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter is not in the Stop domain. |

## Remarks

This method selects the default language and language extensions to use when the disc is played. For example, if *Language* is specified as 0x409 for English and *audioExtension* is specified as DVD_AUD_EXT_NotSpecified, the DVD Navigator will look for the basic audio stream in English. If *audioExtension* is specified as DVD_AUD_EXT_VisuallyImpaired, the DVD Navigator will first look for a special audio stream in English for people with low vision. If the default stream is not found on a disc, the DVD Navigator will select the closest match.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None | DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)