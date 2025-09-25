# IMFClockStateSink::OnClockRestart

## Description

Called when the presentation clock restarts from the same position while paused.

## Parameters

### `hnsSystemTime` [in]

The system time when the clock restarted, in 100-nanosecond units.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called if the presentation clock is paused and the [IMFPresentationClock::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start) method is called with the value **PRESENTATION_CURRENT_POSITION**.

The clock notifies the presentation time source by calling the time source's **OnClockRestart** method. This call occurs synchronously within the [Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-start) method. If the time source returns an error from **OnClockRestart**, the presentation clock's **Start** method returns an error and the state change does not take place.

For any object that is not the presentation time source, the **OnClockRestart** method is called asynchronously, after the state change is completed. In that case, the return value from this method is ignored.

## See also

[IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)