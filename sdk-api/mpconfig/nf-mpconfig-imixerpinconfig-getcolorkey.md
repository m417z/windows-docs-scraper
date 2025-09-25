# IMixerPinConfig::GetColorKey

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetColorKey` method retrieves the color key being used by a video stream.

## Parameters

### `pColorKey` [out]

Pointer to a [COLORKEY](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-colorkey) structure that contains the key type and a palette index.

### `pColor` [out]

Pointer to a value indicating the 8-bit palette index of the [COLORKEY](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-colorkey) returned if the current display mode is 8-bit palettized. Otherwise it is a value representing the color key in the pixel format of the current display mode.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid arguments, both parameters are **NULL**. |
| **E_FAIL** | `GetColorKey` failed because the color key isn't known. |
| **NOERROR** | Success. |

## Remarks

Getting the value on the primary stream will retrieve the destination color key being used by the overlay surface. Getting this value on the secondary pin returns the color key being used by that particular stream.

Current DirectShow implementation of this interface can return **NULL** for either the *pColorKey* or the *pColor* parameters; however, the method will fail and return E_INVALIDARG if both parameters are **NULL**.

**Note** The **DWORD** value returned by the *pColor* parameter is the actual color being used. So, if the bit depth of the display is 8, 16, 24, 32 the last 8, 16, 24 or 32 bits of the **DWORD** specify the actual value of the color key.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::SetColorKey](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-setcolorkey)