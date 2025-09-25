# IMFMediaSinkPreroll::NotifyPreroll

## Description

Notifies the media sink that the presentation clock is about to start.

## Parameters

### `hnsUpcomingStartTime` [in]

The upcoming start time for the presentation clock, in 100-nanosecond units. This time is the same value that will be given to the [IMFPresentationClock::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start) method when the presentation clock is started.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After this method is called, the media sink sends any number of [MEStreamSinkRequestSample](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkrequestsample) events to request samples, until is has enough preroll data. When it has enough preroll data, the media sink sends an [MEStreamSinkPrerolled](https://learn.microsoft.com/windows/desktop/medfound/mestreamsinkprerolled) event. This event signals that the client can start the presentation clock.

During preroll, the media sink can prepare the samples that it receives, so that they are ready to be rendered. It does not actually render any samples until the clock starts.

## See also

[IMFMediaSinkPreroll](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasinkpreroll)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)