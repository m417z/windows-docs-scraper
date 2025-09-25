# IDvdInfo2::GetDVDTextNumberOfLanguages

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDTextNumberOfLanguages` method retrieves the number of languages in which DVD text strings appear.

## Parameters

### `pulNumOfLangs` [out]

Receives the number of text languages.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **E_UNEXPECTED** | An unexpected internal error occurred. |

## Remarks

Depending on how the disc is authored, the number of languages will be valid either for the entire disc, or only for the current side of the disc.

If the DVD does not contain any text strings, the method succeeds, but *pulNumOfLangs* receives the value zero.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Working with DVD Text Strings](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-text-strings)