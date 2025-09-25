# IMFClockStateSink::OnClockStart

## Description

Called when the presentation clock starts.

## Parameters

### `hnsSystemTime` [in]

The system time when the clock started, in 100-nanosecond units.

### `llClockStartOffset` [in]

The new starting time for the clock, in 100-nanosecond units. This parameter can also equal **PRESENTATION_CURRENT_POSITION**, indicating the clock has started or restarted from its current position.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called when the presentation clock's [IMFPresentationClock::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start) method is called, with the following exception: If the clock is paused and **Start** is called with the value **PRESENTATION_CURRENT_POSITION**, [IMFClockStateSink::OnClockRestart](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfclockstatesink-onclockrestart) is called instead of **OnClockStart**.

The clock notifies the presentation time source by calling the time source's **OnClockStart** method. This call occurs synchronously within the [Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start) method. If the time source returns an error from **OnClockStart**, the presentation clock's **Start** method returns an error and the state change does not take place.

For any object that is not the presentation time source, the **OnClockStart** method is called asynchronously, after the state change is completed. In that case, the return value from this method is ignored.

The value given in *llClockStartOffset* is the presentation time when the clock starts, so it is relative to the start of the presentation. Media sinks should not render any data with a presentation time earlier than *llClockStartOffSet*. If a sample straddles the offset—that is, if the offset falls between the sample's start and stop times—the sink should either trim the sample so that only data after *llClockStartOffset* is rendered, or else simply drop the sample.

## See also

[IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)