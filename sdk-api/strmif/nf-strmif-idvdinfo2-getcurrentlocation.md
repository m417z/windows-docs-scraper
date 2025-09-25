# IDvdInfo2::GetCurrentLocation

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentLocation` method retrieves the current playback location.

## Parameters

### `pLocation` [out]

Pointer to a variable of type [DVD_PLAYBACK_LOCATION2](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_playback_location2) that receives the playback location information.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | The *pLocation* parameter is invalid. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is in an invalid domain. |

## Remarks

This method retrieves information sufficient to restart playback of a video from the current playback location in titles that don't explicitly disable seeking to the current location. After the disc has been ejected, the information returned by this method will not necessarily be sufficient to restart playback. To save the current location and state information to disc so that the user can return to the same location at any later time, use [GetState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdinfo2-getstate).

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)