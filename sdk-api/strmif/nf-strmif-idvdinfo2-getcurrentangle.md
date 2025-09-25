# IDvdInfo2::GetCurrentAngle

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetCurrentAngle` method retrieves the number of available angles in the current angle block and the currently selected angle number.

## Parameters

### `pulAnglesAvailable` [out]

Receives the number of available angles. There are up to nine angles in an angle block, numbered 1 through 9. If the value equals 1, then the [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not in an angle block.

### `pulCurrentAngle` [out]

Receives the current angle number.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |
| **VFW_E_DVD_INVALIDDOMAIN** | DVD Navigator is not initialized or not in a valid domain. |

## Remarks

Note that angle and menu button indexes are 1-based, while audio and subpicture stream indexes are 0-based. When the DVD Navigator is about to enter an angle block, it sends the application an [EC_DVD_ANGLES_AVAILABLE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-angles-available) event notification with the *lParam* set to 1. Applications will typically call `GetCurrentAngle` and [IDvdControl2::SelectAngle](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-selectangle) within their event handler for EC_DVD_ANGLES_AVAILABLE.

This method is demonstrated in the DVDSample application in **CAngleDlg::MakeAngleList**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[EC_DVD_ANGLES_AVAILABLE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-angles-available)

[EC_DVD_ANGLE_CHANGE](https://learn.microsoft.com/windows/desktop/DirectShow/ec-dvd-angle-change)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)