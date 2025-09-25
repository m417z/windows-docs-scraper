# IDvdInfo2::GetDVDTextStringAsUnicode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDTextStringAsUnicode` method retrieves a DVD text string for a specified language, and returns the text string as a Unicode string.

## Parameters

### `ulLangIndex` [in]

Zero-based index of the language. To find the number of text-string languages on the DVD, call [IDvdInfo2::GetDVDTextNumberOfLanguages](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextnumberoflanguages).

### `ulStringIndex` [in]

Zero-based index of the string to retrieve. To find the number of strings for a given language, call [IDvdInfo2::GetDVDTextLanguageInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextlanguageinfo).

### `pchwBuffer` [out]

Pointer to a buffer that receives the text string. If *pchBuffer* is **NULL**, this method returns the size of the string in *pulActualSize*.

### `ulMaxBufferSize` [in]

Size of the *pchBuffer* buffer, in **WCHARs**.

### `pulActualSize` [out]

Receives the actual length of the string in characters, including the terminating **NULL**.

### `pType` [out]

Receives a member of the [DVD_TextStringType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_textstringtype) enumeration. The value indicates the type of text string, such as movie title or song name. This parameter can also receive values that are not defined in the **DVD_TextStringType** enumeration.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | Unsupported te |
| **E_POINTER** | Invalid argument. |
| **E_UNEXPECTED** | An unexpected internal error occurred. |

## Remarks

This method supports text strings that are encoded as Unicode or 7-bit ASCII (ISO/IEC 646). If the text string uses ASCII encoding, the method converts the string to a wide-character string. If the text string uses any other character set, the method returns E_FAIL. In that case, you can call [IDvdInfo2::GetDVDTextStringAsNative](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasnative) to retrieve the string as a raw byte array. To find the character set, call [IDvdInfo2::GetDVDTextLanguageInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextlanguageinfo).

The returned string always includes a terminating **NULL**. If the buffer is smaller than the length of the DVD text string, the string is truncated. To find the required size of the buffer, call the method once with *pchBuffer* equal to **NULL** and *ulMaxBufferSize* equal to zero. The size is returned in *pulActualSize*. Then allocate a buffer and call the method again.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)