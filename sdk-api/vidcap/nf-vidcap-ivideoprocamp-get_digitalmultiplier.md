# IVideoProcAmp::get_DigitalMultiplier

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_DigitalMultiplier` method returns the camera's digital zoom level.

## Parameters

### `pValue` [out]

Receives the digital zoom multiplier.

### `pFlags` [out]

Receives one or more flags. See [VideoProcAmpFlags](https://learn.microsoft.com/windows/win32/api/strmif/ne-strmif-videoprocampflags).

## Return value

Returns an **HRESULT** value.

## Remarks

Digital zoom is applied after the image is captured. The effect of digital zoom is to multiply the optical magnification by a factor *m*, which can be calculated as follows:

```cpp

m = ( (Z'cur - Z'min) * (m-max - 1) ) / (Z'max - Z'min) ) + 1

```

where

* Z'cur = Current digital zoom level.
* Z'min, Z'max = Minimum and maximum digital zoom. See [IVideoProcAmp::getRange_DigitalMultiplier](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-ivideoprocamp-getrange_digitalmultiplier).
* m-max = Maximum digital magnification. See KSPROPERTY_VIDEOPROCAMP_DIGITAL_MULTIPLIER_LIMIT, documented in the Windows DDK.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICameraControl::get_FocalLengths](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-get_focallengths)

[IVideoProcAmp Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-ivideoprocamp)