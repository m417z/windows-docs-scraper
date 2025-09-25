# IDvdInfo2::GetDVDTextStringAsNative

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDTextStringAsNative` method retrieves a DVD text string for a specified language, and returns the text string as an array of bytes.

## Parameters

### `ulLangIndex` [in]

Zero-based index of the language. To find the number of text-string languages on the DVD, call [IDvdInfo2::GetDVDTextNumberOfLanguages](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextnumberoflanguages).

### `ulStringIndex` [in]

Zero-based index of the string to retrieve. To find the number of strings for a given language, call [IDvdInfo2::GetDVDTextLanguageInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextlanguageinfo).

### `pbBuffer` [out]

Pointer to a buffer that receives the text string. If *pchBuffer* is **NULL**, this method returns the size of the string in *pulActualSize*.

### `ulMaxBufferSize` [in]

Size of the *pchBuffer* in bytes

### `pulActualSize` [out]

Receives the actual length of the string in bytes, including the terminating **NULL**.

### `pType` [out]

Receives a member of the [DVD_TextStringType](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_textstringtype) enumeration. The value indicates the type of text string, such as movie title or song name. This parameter can also receive values that are not defined in the **DVD_TextStringType** enumeration.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **E_UNEXPECTED** | An unexpected internal error occurred. |

## Remarks

This method returns a DVD text string as a raw byte array, with no conversions. You can use this method to get text strings that are encoded using character sets other than Unicode or 7-bit ASCII (ISO/IEC 646), such as JIS Roman Kanji. To find the character set, call [IDvdInfo2::GetDVDTextLanguageInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextlanguageinfo).

For Unicode and ASCII text strings, you can use the [IDvdInfo2::GetDVDTextStringAsUnicode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getdvdtextstringasunicode) method, which returns a wide-character string.

The returned string always includes a single terminating **NULL** byte. If the buffer is smaller than the length of the DVD text string, the string is truncated. To find the required size of the buffer, call the method once with *pchBuffer* equal to **NULL** and *ulMaxBufferSize* equal to zero. The size is returned in *pulActualSize*. Then allocate a buffer and call the method again.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)