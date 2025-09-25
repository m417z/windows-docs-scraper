# IDvdInfo2::GetCurrentDomain

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentDomain` method retrieves the domain in which the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is currently located.

## Parameters

### `pDomain` [out]

Pointer to a variable of type [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain) that receives the current domain.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected error. |
| **E_POINTER** | Invalid argument. |

## Remarks

You can use this method to test whether the DVD Navigator is finished playing in a particular title domain. An application doesn't have to test for the current domain before calling an [IDvdControl2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdcontrol2) method such as [PlayTitle](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playtitle), [PlayForwards](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-playforwards), and so on. The DVD Navigator tests for the domain and simply does nothing, returning VFW_E_DVD_INVALIDDOMAIN, if the current command is invalid for the domain.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[EC_DVD_DOMAIN_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-domain-change)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)