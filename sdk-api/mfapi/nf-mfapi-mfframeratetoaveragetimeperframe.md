# MFFrameRateToAverageTimePerFrame function

## Description

Converts a video frame rate into a frame duration.

## Parameters

### `unNumerator` [in]

The numerator of the frame rate.

### `unDenominator` [in]

The denominator of the frame rate.

### `punAverageTimePerFrame` [out]

Receives the average duration of a video frame, in 100-nanosecond units.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is useful for calculating time stamps on a sample, given the frame rate.

Also, average time per frame is used in the older [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) and [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) format structures. This function provides a standard conversion so that all components in the pipeline can use consistent values, if they need to translate between the older format structures and the media type attributes used in Media Foundation.

For certain common frame rates, the function gets the frame duration from a look-up table:

| Frames per second (floating point) | Frames per second (fractional) | Average time per frame |
| --- | --- | --- |
| 59.94 | 60000/1001 | 166833 |
| 29.97 | 30000/1001 | 333667 |
| 23.976 | 24000/1001 | 417188 |
| 60 | 60/1 | 166667 |
| 30 | 30/1 | 333333 |
| 50 | 50/1 | 200000 |
| 25 | 25/1 | 400000 |
| 24 | 24/1 | 416667 |

Most video content uses one of the frame rates listed here.
For other frame rates, the function calculates the duration.

## See also

[MFAverageTimePerFrameToFrameRate](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfaveragetimeperframetoframerate)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)