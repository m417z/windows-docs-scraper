# IDvdInfo2::GetPlayerParentalLevel

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetPlayerParentalLevel` method retrieves the current parental level and ISO 3166 country/region code settings for the DVD Navigator.

## Parameters

### `pulParentalLevel` [out]

Receives a value indicating the current parental level. Valid parental levels are 1 through 8 if parental management is enabled, 0xFFFFFFFF if parental management is disabled.

### `pbCountryCode` [out]

Address of a two-byte array that receives the current country/region code (ISO 3166 Alpha-2 Code).

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter is invalid. |

## Remarks

Parental management is disabled by default in the DVD Navigator. This method is demonstrated in the DVDSample application in **CDvdCore::GetParentalLevel**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[EC_DVD_PARENTAL_LEVEL_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-parental-level-change)

[Enforcing Parental Management Levels](https://learn.microsoft.com/windows/desktop/DirectShow/enforcing-parental-management-levels)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)