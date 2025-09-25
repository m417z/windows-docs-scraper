# IStreamBufferMediaSeeking2::SetRateEx

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetRateEx** method sets the playback rate, and sets the frame rate for fast-forward play ("trick mode").

## Parameters

### `dRate` [in]

Playback rate. Valid range is (*dRate* >= 0.1 || *dRate* <= -0.1).

### `dwFramesPerSec` [in]

Frames per second for fast-forward play. Cannot be zero. See Remarks for more information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

At higher frames rates, the Stream Buffer Engine drops delta frames and may skip some key frames. This behavior is determined by the [IStreamBufferConfigure2::SetFFTransitionRates](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferconfigure2-setfftransitionrates) method. When the playback rate exceeds the value given in that method's *dwMaxNonSkippingRate* parameter, the Stream Buffer Engine starts to skip key frames. The number of skipped key frames is determined by the playback rate. To control how many key frames are skipped, use the **SetRateEx** method:

* If the playback rate is less than or equal to *dwMaxNonSkippingRate*, the *dwFramesPerSec* parameter is ignored.
* If the playback rate exceeds *dwMaxNonSkippingRate*, the Stream Buffer Engine maintains the frame rate specified in *dwFramesPerSec* and drops key frames if necessary.

The frame rate is applied to the video stream. If there is no video stream, the method fails. The actual frame rate may vary over short periods of time.

## See also

[IStreamBufferMediaSeeking2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambuffermediaseeking2)