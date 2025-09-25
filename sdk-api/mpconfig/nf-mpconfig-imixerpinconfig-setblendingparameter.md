# IMixerPinConfig::SetBlendingParameter

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetBlendingParameter` method sets the blending parameter that defines how a secondary stream is blended with a primary stream.

## Parameters

### `dwBlendingParameter` [in]

Value between 0 and 255 that indicates the amount of blending between a primary stream and a secondary stream.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | Method called on primary stream. |
| **E_INVALIDARG** | Value outside of possible range (0 to 255). |
| **S_OK** | Success. |

## Remarks

The value of the *dwBlendingParameter* parameter must be between 0 and 255, where 0 makes the secondary stream invisible and 255 makes the primary stream invisible in the area that the secondary stream occupies. If no value is set the default is 255.

This method is not intended to be called on the primary stream.

**Note** Current DirectShow implementation of this interface allows only values of 0 or 255 for the *dwBlendingParameter* parameter. Any other values are invalid.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::GetBlendingParameter](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getblendingparameter)