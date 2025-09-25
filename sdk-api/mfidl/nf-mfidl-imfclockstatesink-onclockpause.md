# IMFClockStateSink::OnClockPause

## Description

Called when the presentation clock pauses.

## Parameters

### `hnsSystemTime` [in]

The system time when the clock was paused, in 100-nanosecond units.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When the presentation clock's [IMFPresentationClock::Pause](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpresentationclock-pause) method is called, the clock notifies the presentation time source by calling the time source's **OnClockPause** method. This call occurs synchronously within the **Pause** method. If the time source returns an error from **OnClockPause**, the presentation clock's **Pause** method returns an error and the state change does not take place.

For any object that is not the presentation time source, the **OnClockPause** method is called asynchronously, after the state change is completed. In that case, the return value from this method is ignored.

## See also

[IMFClockStateSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfclockstatesink)

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Presentation Clock](https://learn.microsoft.com/windows/desktop/medfound/presentation-clock)