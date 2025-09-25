# MFAverageTimePerFrameToFrameRate function

## Description

Calculates the frame rate, in frames per second, from the average duration of a video frame.

## Parameters

### `unAverageTimePerFrame` [in]

The average duration of a video frame, in 100-nanosecond units.

### `punNumerator` [out]

Receives the numerator of the frame rate.

### `punDenominator` [out]

Receives the denominator of the frame rate.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

Average time per frame is used in the older **VIDEOINFOHEADER** and **VIDEOINFOHEADER2** format structures. This function provides a standard conversion so that all components in the pipeline can use consistent values, if they need to translate between the older format structures and the media type attributes used in Media Foundation.

This function uses a look-up table for certain common durations. The table is listed in the Remarks section for the [MFFrameRateToAverageTimePerFrame](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfframeratetoaveragetimeperframe) function.

## See also

[MFFrameRateToAverageTimePerFrame](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfframeratetoaveragetimeperframe)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)