# IMFMediaSink::SetPresentationClock

## Description

Sets the presentation clock on the media sink.

## Parameters

### `pPresentationClock` [in]

Pointer to the [IMFPresentationClock](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpresentationclock) interface of the presentation clock, or **NULL**. If the value is **NULL**, the media sink stops listening to the presentation clock that was previously set, if any.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_CLOCK_NO_TIME_SOURCE** | The presentation clock does not have a time source. Call [SetTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-settimesource) on the presentation clock. |
| **MF_E_SHUTDOWN** | The media sink's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown) method has been called. |

## Remarks

During streaming, the media sink attempts to match rates with the presentation clock. Ideally, the media sink presents samples at the correct time according to the presentation clock and does not fall behind. Rateless media sinks are an exception to this rule, as they consume samples as quickly as possible and ignore the clock. If the sink is rateless, the [IMFMediaSink::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getcharacteristics) method returns the MEDIASINK_RATELESS flag.

The presentation clock must have a time source. Before calling this method, call [IMFPresentationClock::SetTimeSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-settimesource) on the presentation clock to set the presentation time source. Some media sinks provide time sources; therefore, the media sink might be the time source for its own presentation clock. Regardless of what object provides the time source, however, the media sink must attempt to match rates with the clock specified in *pPresentationClock*. If a media sink cannot match rates with an external time source, the media sink's [IMFMediaSink::GetCharacteristics](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-getcharacteristics) method retrieves the MEDIASINK_CANNOT_MATCH_CLOCK flag. In this case, **SetPresentationClock** will still succeed, but the results will not be optimal. The sink might not render samples quickly enough to match rates with the presentation clock.

If *pPresentationClock* is non-**NULL**, the media sink must register for clock state notifications, by calling [IMFPresentationClock::AddClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-addclockstatesink) on the presentation clock. If the method is called again with a new presentation clock, or if *pPresentationClock* is **NULL**, the media sink must call [IMFPresentationClock::RemoveClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-removeclockstatesink) to deregister itself from the previous clock.

All media sinks must support this method.

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)