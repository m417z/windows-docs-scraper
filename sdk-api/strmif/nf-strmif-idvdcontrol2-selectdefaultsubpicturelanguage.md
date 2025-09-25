# IDvdControl2::SelectDefaultSubpictureLanguage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SelectDefaultSubpictureLanguage` method sets the default language for subpicture text.

## Parameters

### `Language` [in]

Locale identifier that specifies the default language.

### `subpictureExtension` [in]

[DVD_SUBPICTURE_LANG_EXT](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_subpicture_lang_ext) enumeration that specifies the default subpicture extension.

## Return value

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | *Language* is invalid. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) filter is not in a valid domain. |

## Remarks

This method selects the default language and format to use for subpictures and menus when the disc is played. For example, if *Language* is specified as 0x409 for U.S. English and *subpictureExtension* is specified as DVD_SP_EXT_Caption_Big, the DVD Navigator tries to show U.S. English text in the "big caption" format in subpictures. If the default language or language extension is not found on a disc, the DVD Navigator selects the closest match.

The following table shows the Annex J command name to which this method name corresponds, and the domains in which this method is valid.

|  |  |
| --- | --- |
| Annex J Command Name | Valid Domains |
| None | DVD_DOMAIN_Stop |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2)