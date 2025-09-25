# IDvdInfo2::GetSubpictureLanguage

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSubpictureLanguage` method retrieves the language of the specified subpicture stream within the current title.

## Parameters

### `ulStream` [in]

Number of the subpicture stream for which the language is being retrieved.

### `pLanguage` [out]

Pointer to an LCID that receives the locale information. The language information can then be extracted from the LCID by using the Win32 **MAKELANGID** macro.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized or not in a valid domain. |

## Remarks

To get the text languages available for a menu, call [GetMenuLanguages](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getmenulanguages). `GetSubpictureLanguage` sets the value pointed to by *pLanguage* to zero if the stream contains an unknown language. Call the Win32 **GetLocaleInfo** function as follows to create a human-readable string name from *pLanguage*:

| C++ |
| --- |
| ``` LCID Language; hr = pDvdInfo->GetSubpictureLanguage(ulStream, &Language); if (SUCCEEDED(hr)) {     int cchSize = GetLocaleInfo(Language, LOCALE_SENGLANGUAGE, 0, 0);     TCHAR *szString = new TCHAR[cchSize];     if (szString)     {         GetLocaleInfo(Language, LOCALE_SENGLANGUAGE, szString, cchSize);         /* ... */         delete [] szString;     } } ``` |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)