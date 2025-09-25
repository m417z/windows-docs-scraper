# IStreamBufferConfigure2::SetFFTransitionRates

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetFFTransitionRates** method sets the behavior of fast-forward play ("trick mode") in the Stream Buffer Engine.

## Parameters

### `dwMaxFullFrameRate` [in]

Maximum playback rate for full-frame playback. The value must be greater than 1. The default value is 4.

### `dwMaxNonSkippingRate` [in]

Maximum playback rate for key-frame playback. The value must be greater than *dwFullFrameRate*. The default value is 6.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

At higher playback rates, the Stream Buffer Engine drops frames in order to maintain the desired rate. The following table shows how the values of *dwMaxFullFrameRate* and *dwMaxNonSkippingRate* affect playback.

| Playback rate | Behavior |
| --- | --- |
| rate <= *dwMaxFullFrameRate* | Full-frame playback: All frames are sent. |
| *dwMaxFullFrameRate* < rate <= *dwMaxNonSkippingRate* | Key-frame playback: All key frames are sent. Delta frames are skipped. |
| *dwMaxNonSkippingRate* < rate | Key-frame playback with seeking: All delta frames are skipped, and some key frames are skipped. The number of skipped key frames is proportional to the rate. |

The decoder may drop frames as well, depending on the data rate, the monitor refresh rate, and the CPU load.

## See also

[IStreamBufferConfigure2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure2)

[IStreamBufferMediaSeeking2::SetRateEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambuffermediaseeking2-setrateex)