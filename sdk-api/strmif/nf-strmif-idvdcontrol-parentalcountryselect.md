# IDvdControl::ParentalCountrySelect

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdControl** interface is deprecated. Use [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) instread.

Sets the current country/region for controlling parental access levels.

## Parameters

### `wCountry` [in]

Value that specifies the current country/region according to the Alpha-2 Code defined in ISO3166. See Remarks.

## Return value

Returns an **HRESULT** value.

## Remarks

This method returns an error unless the domain is DVD_DOMAIN_Stop. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

The ISO3166 2-letter country/region codes in the *wCountry* parameter must be supplied to this method as a WORD. The conversion is demonstrated for the United States (US) in the following line of code.

| C++ |
| --- |
| ``` WORD wCountry  =  ( WORD( 'U' ) << 8 ) | 'S'; ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol)

[IDvdControl::ParentalLevelSelect](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol-parentallevelselect)