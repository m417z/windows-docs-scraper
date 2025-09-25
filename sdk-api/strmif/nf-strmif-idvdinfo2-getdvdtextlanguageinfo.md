# IDvdInfo2::GetDVDTextLanguageInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDTextLanguageInfo` method retrieves information about the text strings for a specified language. The method retrieves the number of strings for that language, the locale identifier, and the character set.

## Parameters

### `ulLangIndex` [in]

Zero-based index of the language to query. To find the number of text-string languages on the DVD, call [IDvdInfo2::GetDVDTextNumberOfLanguages](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextnumberoflanguages).

### `pulNumOfStrings` [out]

Receives the number of text strings for the specified language.

### `pLangCode` [out]

Receives a *locale identifier* (LCID) that specifies the language in which the text is written. For example, the LCID for "en-us" is 0x0409.

### `pbCharacterSet` [out]

Receives a member of the [DVD_TextCharSet](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_textcharset) enumeration. The value specifies the character set of the text string.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | This DVD does not have any text strings, or the *ulLangIndex* parameter is out of bounds. |
| **E_POINTER** | **NULL** pointer argument. |
| **E_UNEXPECTED** | An unexpected internal error occurred. |

## Remarks

To get a particular text string, call [IDvdInfo2::GetDVDTextStringAsUnicode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasunicode) or [IDvdInfo2::GetDVDTextStringAsNative](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasnative).

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)