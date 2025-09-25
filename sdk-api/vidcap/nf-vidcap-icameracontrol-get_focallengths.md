# ICameraControl::get_FocalLengths

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_FocalLengths` method returns the focal lengths of the camera lenses.

## Parameters

### `plOcularFocalLength` [out]

Receives the ocular focal length.

### `plObjectiveFocalLengthMin` [out]

Receives the minimum objective focal length.

### `plObjectiveFocalLengthMax` [out]

Receives the maximum objective focal length.

## Return value

Returns an **HRESULT** value.

## Remarks

In a two-lens camera, the objective lens is closer to the subject, and the ocular lens is closer to the camera. The ocular focal length is fixed. If the camera has an optical zoom, the objective focal length can vary within a fixed range. Magnification is calculated as the ratio of objective/ocular focal length. Because the magnification is expressed as a ratio, it has no units. Therefore, the units for the focal length are not defined by this interface.

If the camera supports optical zooming, the current zoom level is expressed as integer values between a range *Zmin* and *Zmax*. The objective focal length can then be calculated as follows:

```cpp

Lcur = ( ( (Zcur - Zmin) * (Lmax - Lmin) ) / (Zmax - Zmin) ) + Lmin

```

where:

* Lcur = Current objective focal length.
* Lmin, Lmax = Minimum and maximum objective focal length.
* Zcur = Current zoom setting. See [ICameraControl::get_Zoom](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-get_zoom).
* Zmin, Zmax = Minimum and maximum zoom setting. See [ICameraControl::getRange_Zoom](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-icameracontrol-getrange_zoom).

From

```
Lcur
```

, you can calculate the magnification.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[ICameraControl Interface](https://learn.microsoft.com/windows/desktop/api/vidcap/nn-vidcap-icameracontrol)