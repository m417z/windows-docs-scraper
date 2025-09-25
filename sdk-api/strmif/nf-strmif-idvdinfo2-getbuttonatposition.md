# IDvdInfo2::GetButtonAtPosition

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetButtonAtPosition` method retrieves the button located at the specified point within the display window.

## Parameters

### `point` [in]

Current mouse pointer position as retrieved through the Win32 WM_MOUSEMOVE message.

### `pulButtonIndex` [out]

Receives the index (from 1 through 36) of the button at the current mouse pointer position.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | The *puButtonIndex* parameter is invalid. |
| **VFW_E_DVD_NO_BUTTON** | No button at *point*. |

## Remarks

This method is typically called in response to a mouse pointer move within a DVD menu display window. Be sure to check for success in the **HRESULT** before trying to retrieve the button number; this method only sets the value of *puButtonIndex* if a button is found at the specified point. DVD buttons do not necessarily have highlighted rectangles, button rectangles can overlap, and button rectangles do not always correspond to the visual representation of the buttons.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)